//RECTANGULAR MESH

#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include<GL/GL.H>
#include<GL/GLAUX.H>
#include<GL/GLU.h>
#include<math.h>
	
#define maxx 4
#define maxy 4
#define dx 220
#define dy 200
int wind1,wind2,wind3;
int xMouse,yMouse;
int k;
int open_win;
int box_mark[10]={0};
float win_x=1280;
float win_y=768;
const float DEG2RAD = 3.14159/180;


void game_begin(int window_no,GLfloat w,GLfloat h);


bool player[2]={FALSE};
int object_map[9][2] = {{175,168},{357,168},{540,168},{175,366},{357,366},{540,366},{175,566},{357,566},{540,566}};

GLubyte label1[]="                     H    A    M    S    A           S     H      W    E    T    H     A    ";
GLubyte present[]="                                            P R E S E N T S            ";
GLubyte ttt[]="                                        T H E  C L A S S I C  G A M E  O F ";
GLubyte ttt1[]="                                          T  I  C    T  A  C   T  O  E   ";
GLubyte enter[]="Enter";
GLubyte game[]="game";
GLubyte arrow[]="press E";
GLubyte quit[]="Quit";
GLubyte enter1[]="                          SIDE BAR";
GLubyte label[]={'H'};
GLubyte label5[]={'T'};
GLfloat x[maxx]={0.0},y[maxy]={0.0};
GLfloat xO=100.0;
GLfloat yO=100.0;
GLint i,j;
int winid;
void init()
{
	glClearColor(0.5,0.2,0.5,1.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,1280.0,0.0,768.0);
	glutPostRedisplay();
}

void drawPoly()
{
	//glColor3f(0.0,0.0,1.0);
	glDisable(GL_LIGHTING);
	
	//glTranslatef(100,500,0);
	//glRotatef(3.0,1,0,0);
	/*for(k=0;k<40;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,label1[k]);
	//glPixelZoom(200,200);
	}
     glFlush();*/
	//glEnable(GL_LIGHTING);
	glColor3f(1.0,1.0,0.0);
	glLineWidth(4.0);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINES);
	glVertex2f(800,0);
	glVertex2f(800,760);
	glEnd();
	glDisable(GL_LIGHTING);
	glColor3f(0.1,0.1,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(810.0,0.0);
	glVertex2f(1279.0,0.0);
	glVertex2f(1279.0,810.0);
	glVertex2f(810.0,810.0);
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,1.0);
    glRasterPos2f(830.0,600.0);
	for(int k=0;k<36;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,enter1[k]);
	}
	glFlush();
		

}


void meshDraw(void)
{
   glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.5,1.0);
	GLfloat light1[]={512.0,384.0,0.0,0.0};
	glLightfv(GL_LIGHT1,GL_POSITION,light1);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	GLfloat light2[]={0.1,0.1,1.0,0.0};
    glLightfv(GL_LIGHT0,GL_SPECULAR,light2);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	//glColor3f(0.0,0.0,1.0);
	glLineWidth(3.0);
	for(i=0;i<maxx;i++)
		x[i]=xO+(float)(i*dx);
	for(j=0;j<maxy;j++)
		y[j]=yO+(float)(j*dy);
	glColor3f(1.0,0.0,0.0);
	for(i=0;i<maxx-1;i++)
		//glColor3f(1.0,0.0,0.0);
		for(j=0;j<maxy-1;j++)
		{
			glColor3f(1.5,0.5,0.5);
			glBegin(GL_LINE_LOOP);
			glVertex2f(x[i],y[j]);
			glVertex2f(x[i],y[j+1]);
			glVertex2f(x[i+1],y[j+1]);
			glVertex2f(x[i+1],y[j]);
			glEnd();
			glFlush();
			glColor3f(0.0,1.0,0.0);
			glPointSize(4.0);
			glBegin(GL_POINTS);
			glVertex2f((x[i]+x[i+1])/2,(y[j]+y[j+1])/2);
			//x.point[i]=((x[i]+x[i+1])/2);
			//y.point[j]=((y[j]+y[j+1])/2);
			glEnd();
			glFlush();
		}
	glFinish();
	drawPoly();
}

void DrawEllipse(float xradius, float yradius)
{    
//	int i;
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_LINE_LOOP);
 
   for (int i=0; i<=360; i++)
   {
      //convert degrees into radians
      float degInRad = i*DEG2RAD;
      glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
	     glScalef(350.0f,250.0f,0.0f);
   }
          glTranslatef(450.0,45.0,0.0);

  glEnd();
  glFlush();

	//glColor3f(0.0,0.0,1.0);
	glDisable(GL_LIGHTING);
	
	glColor3f(0.1,0.1,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(220.0,320.0);
	glVertex2f(320.0,320.0);
	glVertex2f(320.0,220.0);
	glVertex2f(220.0,220.0);
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,1.0);
    glRasterPos2f(230.0,290.0);
	for(int k=0;k<=5;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,enter[k]);

	}
	glFlush();

	glColor3f(0.0,1.0,1.0);
    glRasterPos2f(240.0,270.0);
	for( k=0;k<=4;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,game[k]);

	}
	glFlush();

	glColor3f(0.0,1.0,1.0);
    glRasterPos2f(240.0,240.0);
	for( k=0;k<=7;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,arrow[k]);

	}
	glFlush();	
		   
		   
}

void display(void)
{
	int k,cur;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.5,0.5);
	glLineWidth(2.0);

	//LIGHT SETTINGS
	GLfloat light1[]={0.0,0.0,0.0,1.0};
	glLightfv(GL_LIGHT1,GL_AMBIENT,light1);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

	GLfloat light2[]={0.1,0.0,1.0,0.0};
    glLightfv(GL_LIGHT0,GL_SPECULAR,light2);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);

	glDisable(GL_LIGHTING);
	glColor3f(0.0,1.0,1.0);
	glRasterPos2i((int)120,(int)656);
	for(k=0;k<90;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,label1[k]);
	}
	     glFlush();


    glColor3f(0.5,1.0,1.0);
	glRasterPos2i((int)160,(int)616);
	for(k=0;k<70;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,present[k]);
	}
	     glFlush();

		 glColor3f(0.0,1.0,1.0);
	glRasterPos2i((int)100,(int)556);
	for(k=0;k<75;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ttt[k]);
	}
	     glFlush();

	glColor3f(1.5,1.5,1.5);
	glRasterPos2i((int)120,(int)486);
	for(k=0;k<76;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,ttt1[k]);
	}
	     glFlush();

		 glDisable(GL_LIGHTING);

    glColor3f(0.0,1.5,0.2);
	glBegin(GL_LINES);
	glVertex2f(450,400);
	glVertex2f(700,400);
	glVertex2f(450,350);
	glVertex2f(700,350);
	glVertex2f(450,300);
	glVertex2f(700,300);
	glVertex2f(450,250);
	glVertex2f(700,250);
	glColor3f(1.5,0.0,0.5);
	glVertex2f(490,210);
	glVertex2f(490,450);
	glVertex2f(540,210);
	glVertex2f(540,450);
	glVertex2f(590,210);
	glVertex2f(590,450);
	glVertex2f(640,210);
	glVertex2f(640,450);
	glEnd();
	
	glFlush();

	glColor3f(0.1,0.1,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(820.0,320.0);
	glVertex2f(910.0,320.0);
	glVertex2f(910.0,220.0);
	glVertex2f(820.0,220.0);
	glEnd();
	glFlush();

	glColor3f(0.0,1.0,1.0);
	glRasterPos2i((int)830,(int)270);
	for(k=0;k<15;k++)
	{
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,quit[k]);
	}
	     glFlush();




		 DrawEllipse(40.5f,30.0f);


}

void idle()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
glPushMatrix();
glTranslated(0.5,0.5*2,0.5);
glScaled(1.0,0.02,1.0);
glutSolidCube(5.0);
glFlush();
glPopMatrix();
	
}



void plotH(int x,int y)
{
	glColor3f(0.0,1.0,0.0);
	glLineWidth(5.0);	

    glRasterPos2f(x,y);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,label[0]);
	glFlush();
}

void plotT(int x,int y)
{
	glColor3f(1.0,0.0,0.0);
	glRasterPos2f(x+75,y+75);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,label5[0]);
	glEnd();
	glFlush();
}

void key(GLubyte key,GLint x,GLint y)
{
	switch(key)
	{
	case 'E':
	case 'e':
		glutDestroyWindow(open_win);

	 	game_begin(2,1280,768);
		break;

	case 'q':
		exit(0);
		break;
	}

}

void convertCoord(char pawn,int xDiff,int yDiff,int x ,int y)
{
            GLint viewport[4]; //var to hold the viewport info
            GLdouble modelview[16]; //var to hold the modelview info
            GLdouble projection[16]; //var to hold the projection matrix info
            GLfloat winX, winY, winZ; //variables to hold screen x,y,z coordinates
            GLdouble worldX, worldY, worldZ; //variables to hold world x,y,z coordinates

			glGetDoublev( GL_MODELVIEW_MATRIX, modelview ); //get the modelview info
			glGetDoublev( GL_PROJECTION_MATRIX, projection ); //get the projection matrix info
			glGetIntegerv( GL_VIEWPORT, viewport ); //get the viewport info

		winX = (float)x;
        winY = (float)viewport[3] - (float)y;
		winZ = 0;
		printf("x=%d,y=%d",x,y);
		
	//get the world coordinates from the screen coordinates
gluUnProject( winX, winY, winZ, modelview, projection, viewport, &worldX, &worldY, &worldZ);

switch(pawn)
{
case 'h':plotH(winX+xDiff,winY);
	break;

case 't':plotT(winX+xDiff,winY+yDiff);
	break;
}
}
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		if((x>=83&&x<=265) && (y>=67&&y<=267))
		{
			box_mark[1]=1;
			convertCoord('h',25,20,x,y);

		}
		if((x>=265&&x<=448) && (y>=67&&y<=267))
		{
			box_mark[2]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=448&&x<=632) && (y>=67&&y<=267))
		{
			box_mark[3]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=83&&x<=265) && (y>=267&&y<=465))
		{
			box_mark[4]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=265&&x<=448) && (y>=267&&y<=465))
		{
			box_mark[5]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=448&&x<=632) && (y>=267&&y<=465))
		{
			box_mark[6]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=83&&x<=265) && (y>=465&&y<=667))
		{
			box_mark[7]=1;
			convertCoord('h',50,20,x,y);
		}
        if((x>=265&&x<=448) && (y>=465&&y<=667))
		{
			box_mark[8]=1;
			convertCoord('h',50,20,x,y);
		}
		if((x>=448&&x<=632) && (y>=465&&y<=667))
		{
			box_mark[9]=1;
			convertCoord('h',50,20,x,y);
		}

		

	}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
         if((x>=83&&x<=265) && (y>=67&&y<=267))
		{
			box_mark[1]=0;
			convertCoord('t',25,0,x,y);

		}
		if((x>=265&&x<=448) && (y>=67&&y<=267))
		{
			box_mark[2]=0;
			convertCoord('t',20,0,x,y);
		}
		if((x>=448&&x<=632) && (y>=67&&y<=267))
		{
			box_mark[3]=0;
			convertCoord('t',20,0,x,y);
		}
		if((x>=83&&x<=265) && (y>=267&&y<=465))
		{
			box_mark[4]=0;
			convertCoord('t',20,0,x,y);
		}
		if((x>=265&&x<=448) && (y>=267&&y<=465))
		{
			box_mark[5]=0;
			convertCoord('t',20,0,x,y);
		}
		if((x>=448&&x<=632) && (y>=267&&y<=465))
		{
			box_mark[6]=0;
			convertCoord('t',20,0,x,y);
		}
		if((x>=83&&x<=265) && (y>=465&&y<=667))
		{
			box_mark[7]=0;
			convertCoord('t',50,0,x,y);
		}
        if((x>=265&&x<=448) && (y>=465&&y<=667))
		{
			box_mark[8]=0;
			convertCoord('t',50,0,x,y);
		}
		if((x>=448&&x<=632) && (y>=465&&y<=667))
		{
			box_mark[9]=0;
			convertCoord('t',50,0,x,y);
		}
	
	}
}

void game_begin(int window_no,GLfloat w,GLfloat h)
{
	
	switch(window_no)
	{
	case 1:
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
    wind1=open_win=glutCreateWindow("MAIN MENU");
	glutSetWindow(wind1);
	glutShowWindow();
	
   	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutIdleFunc(idle);

	break;

	case 2:
		
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(w,h);
    wind2=open_win=glutCreateWindow("Play Game");
	glutSetWindow(wind2);
	glutShowWindow();
    glutDisplayFunc(meshDraw);
    glutMouseFunc(mouse);
	glutIdleFunc(NULL);
	init();
	
	break;

	}
}





void main(int argc,char ** argv)
{
	int wind1,wind2;
	printf("Game developed by preet singh\n");
	printf("USN :4VV08CS017\n");
	printf("College : hmritm\n");
    glutInit(&argc,argv);

	game_begin(1,1024,768);
	init();
	glutMainLoop();
}

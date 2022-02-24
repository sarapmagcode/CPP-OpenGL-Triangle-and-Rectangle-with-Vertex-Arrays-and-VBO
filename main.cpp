#define GLEW_STATIC

#include<GL/glew.h>
#include<GL/glut.h>
#include <GL/freeglut_ext.h>
#include<iostream>

using namespace std;

void display();
void triangle();
void rectangle();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutCreateWindow("OpenGL Setup Test");
	glutDisplayFunc(display);
	GLenum err = glewInit();
	if (err == GLEW_OK) {
		glutMainLoop();
	} else {
		cout << "Error in initializing GLEW extension library...";
	}
	return 0;
}

void triangle() {
	GLfloat triangleVertices[] = {
		-0.6f, 0.0f, 0.0f,
		0.0f, 0.8f, 0.0f,
		0.6f, 0.0f, 0.0f
	};
	
	GLfloat colors[] = {
		1.0f, 5.0f, 0.0f,
		0.0f, 1.0f, 5.0f,
		5.0f, 0.0f, 1.0f,
	};
	
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	
	glVertexPointer(3, GL_FLOAT, 0, triangleVertices);
	glColorPointer(3, GL_FLOAT, 0, colors);
	
	// draw triangle
	glDrawArrays(GL_TRIANGLES, 0, 3);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
}

void rectangle() {
	GLfloat rectangleVertices[] = {
		-0.8f, -0.8f, 0.0f,
		-0.8f, 0.0f, 0.0f,
		0.8f, 0.0f, 0.0f,
		0.8f, -0.8f, 0.0f
	};
	
	GLfloat colors[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
		
		1.0f, 0.0f, 1.0f,
		0.0f, 1.0f, 0.0f,
		1.0f, 0.0f, 01.0f,
	};
	
	GLuint VBOid, VBOid2;
	glGenBuffers(1, &VBOid);
	glBindBuffer(GL_ARRAY_BUFFER, VBOid);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 12, rectangleVertices, GL_STATIC_DRAW);
	
	// bind rectangle
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, 0);
	
	// bind gradient colors
	glBindBuffer(GL_ARRAY_BUFFER, VBOid2);
	glColorPointer(6, GL_FLOAT, 0, colors);
	
	// draw rectangle
	glDrawArrays(GL_QUADS, 0, 4);
	
	glDisableClientState(GL_VERTEX_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glDeleteBuffers(1, &VBOid);
	glDeleteBuffers(1, &VBOid2);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(4.0);
	triangle();
	rectangle();
	glFlush();
}


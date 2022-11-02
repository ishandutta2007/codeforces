#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <deque>
#include <map>
#ifdef DEBUG
	#define debug(...) \
	fprintf(stderr,__VA_ARGS__)
#else
	#define debug(...) 
#endif
using namespace std;

double a,b,m;
double vx,vy,vz;
double x,z;
double time;

int main()
{
	scanf("%lf %lf %lf",&a,&b,&m);
	scanf("%lf %lf %lf",&vx,&vy,&vz);
	time=m/(-vy);
	x=a/2;
	x+=time*vx;
	z=time*vz;
	while (x>a)
		x-=2*a;
	while (x<-a)
		x+=2*a;
	while (z>b)
		z-=2*b;
	while (z<-b)
		z+=2*b;
	if (z<0)
		z=-z;
	if (x<0)
		x=-x;
	printf("%.13lf %.13lf\n",x,z);
}
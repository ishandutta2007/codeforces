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

int n,i;
double x[600],y[600];
double PI=acos(-1);

double dtr(double x)
{
	return x*PI/180;
}
int main()
{
	scanf("%d",&n);
	printf("%d\n",4*n+1);
	for (i=0;i<n;++i)
	{
		x[4*i]=i*20*cos(dtr(36));
		y[4*i]=0;
		x[4*i+1]=x[4*i]+10*cos(dtr(36));
		y[4*i+1]=10*sin(dtr(36));
		x[4*i+2]=x[4*i]+10*cos(dtr(72));
		y[4*i+2]=-10*sin(dtr(72));
		x[4*i+3]=x[4*i+2]+10;
		y[4*i+3]=y[4*i+2];
	}
	x[4*n]=n*20*cos(dtr(36));
	y[4*n]=0;
	for (i=0;i<=4*n;++i)
		printf("%.15lf %.15lf\n",x[i],y[i]);
	for (i=0;i<n;++i)
		printf("%d %d %d %d %d\n",4*i+1,4*i+2,4*i+5,4*i+4,4*i+3);
	printf("1");
	for (i=1;i<=n;++i)
		printf(" %d",4*i+1);
	for (i=n-1;i>=0;--i)
	{
		printf(" %d %d %d %d",4*i+3,4*i+2,4*i+4,4*i+1);
	}
	printf("\n");
}
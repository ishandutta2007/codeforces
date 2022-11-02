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

int n,m,k;
double x[5005];
double y[5005];
double z[5005];
int i,j;
double maxx=-1;
double maxy=-1;
double minz=1000000000;
double a,b;
double maxi;
int main()
{
	scanf("%d",&n);
	for (i=0;i<n;++i)
	{
		scanf("%lf",&x[i]);
		maxx=max(maxx,x[i]);
	}
	scanf("%d",&m);
	for (i=0;i<m;++i)
	{
		scanf("%lf",&y[i]);
		maxy=max(maxy,y[i]);
	}
	scanf("%d",&k);
	for (i=0;i<k;++i)
	{
		scanf("%lf",&z[i]);
		minz=min(minz,z[i]);
	}
	scanf("%lf %lf",&a,&b);
	maxi=-1;
	for (i=0;i<m;++i)
	{
		maxi=max(maxi,sqrt((b*y[i]*maxx*maxx)/(minz*a+y[i]*b)));
	}
	printf("%.15lf\n",maxi);
}
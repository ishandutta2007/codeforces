#include <bits/stdc++.h>

using namespace std;

long long y[2],x[2],d[2];

int main()
{
	long long ii,ly,lx;
	double z;
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld%lld%lld",y+ii,x+ii,d+ii);
	}
	ly=y[0]-y[1];
	lx=x[0]-x[1];
	z=(double)sqrt(ly*ly+lx*lx)-d[0]-d[1];
	printf("%.15lf\n",max(max(z/2,(-z-min(d[0],d[1])*2)/2),(double)0));
}
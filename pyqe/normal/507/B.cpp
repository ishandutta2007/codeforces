#include <bits/stdc++.h>

using namespace std;

long long n,d,ub=2e5,ys,xs,yf,xf;

int main()
{
	long long k,ly,lx,lh,rh,md,zz;
	
	scanf("%lld%lld%lld%lld%lld",&n,&ys,&xs,&yf,&xf);
	ly=ys-yf;
	lx=xs-xf;
	d=ly*ly+lx*lx;
	for(lh=0,rh=ub/n;lh<=rh;)
	{
		md=(lh+rh)/2;
		k=n*2*md;
		if(k*k>=d)
		{
			zz=md;
			rh=md-1;
		}
		else
		{
			lh=md+1;
		}
	}
	printf("%lld\n",zz);
}
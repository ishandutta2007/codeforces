#include <bits/stdc++.h>

using namespace std;

long long n[2],d,xs,ys,xf,yf,inf=1e18;

double ds(double x,double y,double x2,double y2)
{
	double lx=x-x2,ly=y-y2;
	
	return sqrt(lx*lx+ly*ly);
}

int main()
{
	long long ii,jj;
	double x,y,x2,y2,z;
	
	scanf("%lld%lld%lld%lld%lld%lld%lld",n,n+1,&d,&xs,&ys,&xf,&yf);
	z=abs(xs-xf)+abs(ys-yf);
	if(n[0]&&n[1])
	{
		for(ii=0;ii<2;ii++)
		{
			if(ii)
			{
				swap(xs,ys);
			}
			x=xs;
			y=(double)(-xs*n[ii]-d)/n[!ii];
			if(ii)
			{
				swap(xs,ys);
				swap(x,y);
			}
			for(jj=0;jj<2;jj++)
			{
				if(jj)
				{
					swap(xf,yf);
				}
				x2=xf;
				y2=(double)(-xf*n[jj]-d)/n[!jj];
				if(jj)
				{
					swap(xf,yf);
					swap(x2,y2);
				}
				z=min(z,ds(xs,ys,x,y)+ds(x,y,x2,y2)+ds(x2,y2,xf,yf));
			}
		}
	}
	printf("%.20lf\n",z);
}
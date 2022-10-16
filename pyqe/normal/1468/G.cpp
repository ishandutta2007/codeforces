#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,ys,xs;
pair<long long,long long> a[200069];

long long cmp(long long x,long long y,long long x2,long long y2)
{
	return x*y2<=x2*y;
}

long long cmp2(long long x,long long y,long long x2,long long y2)
{
	return x*y2==x2*y;
}

int main()
{
	long long i,y,x,l;
	double m1,c1,m2,c2,yi,xi,ly,lx,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",&x,&y);
		a[i]={y,x};
	}
	ys=y+d;
	xs=x;
	l=n;
	for(i=n-1;i;i--)
	{
		if(cmp(ys-a[i].fr,xs-a[i].sc,ys-a[l].fr,xs-a[l].sc))
		{
			if(!cmp2(a[i+1].fr-a[i].fr,a[i+1].sc-a[i].sc,ys-a[l].fr,xs-a[l].sc))
			{
				m1=(double)(a[i+1].fr-a[i].fr)/(a[i+1].sc-a[i].sc);
				c1=(double)a[i].fr-m1*a[i].sc;
				if(xs!=a[l].sc)
				{
					m2=(double)(ys-a[l].fr)/(xs-a[l].sc);
					c2=(double)ys-m2*xs;
					xi=(c1-c2)/(m2-m1);
				}
				else
				{
					xi=xs;
				}
			}
			else
			{
				xi=a[i+1].sc;
			}
			yi=m1*xi+c1;
			ly=yi-a[i].fr;
			lx=xi-a[i].sc;
			z+=sqrt(ly*ly+lx*lx);
			l=i;
		}
	}
	printf("%.20lf\n",z);
}
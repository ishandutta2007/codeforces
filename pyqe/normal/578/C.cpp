#include <bits/stdc++.h>

using namespace std;

long long n,a[200069],inf=1e18;

int main()
{
	long long i;
	double k,sm,lh,rh,md,mx,mn,zx,zn,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(lh=-1e9,rh=1e9;lh+1e-11<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		mx=0;
		mn=0;
		zx=-inf;
		zn=inf;
		for(i=1;i<=n;i++)
		{
			k=(double)a[i]-md;
			sm+=k;
			zx=max(zx,sm-mn);
			zn=min(zn,sm-mx);
			mx=max(mx,sm);
			mn=min(mn,sm);
		}
		z=min(z,max(zx,-zn));
		if(zx>=-zn)
		{
			lh=md;
		}
		else
		{
			rh=md;
		}
	}
	printf("%.15lf\n",z);
}
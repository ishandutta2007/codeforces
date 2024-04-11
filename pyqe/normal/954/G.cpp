#include <bits/stdc++.h>

using namespace std;

long long n,m,d,aa[500069],a[500069];

int main()
{
	long long i,k,lh,rh,md,zz,sm,z;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",aa+i);
	}
	for(lh=0,rh=2e18;lh<=rh;)
	{
		md=(lh+rh)/2;
		sm=0;
		z=0;
		for(i=1;i<=n;i++)
		{
			a[i]=aa[i];
		}
		for(i=1-m;i<=n;i++)
		{
			if(i+m>0&&i+m<=n)
			{
				sm+=a[i+m];
			}
			if(i>0)
			{
				k=max(md-sm,0ll);
				a[min(i+m,n)]+=k;
				sm+=k;
				z+=k;
				if(z>d)
				{
					break;
				}
			}
			if(i-m>0)
			{
				sm-=a[i-m];
			}
		}
		if(z<=d)
		{
			zz=md;
			lh=md+1;
		}
		else
		{
			rh=md-1;
		}
	}
	printf("%lld\n",zz);
}
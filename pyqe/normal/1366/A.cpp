#include <bits/stdc++.h>

using namespace std;

long long a[2],inf=1e18;

int main()
{
	long long t,rr,i,ii,k,lh,rh,md,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",a+ii);
		}
		z=-inf;
		for(lh=0,rh=min(a[0],a[1]);lh<=rh;)
		{
			md=(lh+rh)/2;
			k=a[0]+a[1]-md*2;
			z=max(z,min(md,k));
			if(k<=md)
			{
				rh=md-1;
			}
			else
			{
				lh=md+1;
			}
		}
		printf("%lld\n",z);
	}
}
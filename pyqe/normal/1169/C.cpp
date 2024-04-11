#include <bits/stdc++.h>

using namespace std;

long long n,dv,a[300069],b;

int main()
{
	long long i,lh,rh,md,z=-1;
	bool bad;
	
	scanf("%lld%lld",&n,&dv);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
	}
	lh=0;
	rh=dv-1;
	for(md=(lh+rh)/2;lh<=rh;md=(lh+rh)/2)
	{
		bad=0;
		b=0;
		for(i=0;i<n;i++)
		{
			if((b+dv-a[i])%dv>md)
			{
				if(a[i]>=b)
				{
					b=a[i];
				}
				else
				{
					bad=1;
					break;
				}
			}
		}
		if(bad)
		{
			lh=md+1;
		}
		else
		{
			z=md;
			rh=md-1;
		}
	}
	printf("%lld\n",z);
}
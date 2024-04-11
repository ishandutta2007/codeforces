#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long i,k,lh,rh,md,zz,sm,z=inf;
	
	scanf("%lld",&n);
	for(i=1;i<=162;i++)
	{
		for(lh=0,rh=1e9;lh<=rh;)
		{
			md=(lh+rh)/2;
			if(md*(md+i)<=n)
			{
				zz=md;
				lh=md+1;
			}
			else
			{
				rh=md-1;
			}
		}
		if(zz*(zz+i)==n)
		{
			sm=0;
			for(k=zz;k;sm+=k%10,k/=10);
			if(sm==i)
			{
				z=min(z,zz);
			}
		}
	}
	if(z==inf)
	{
		z=-1;
	}
	printf("%lld\n",z);
}
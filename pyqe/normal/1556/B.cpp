#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,ex[100069];

int main()
{
	long long t,rr,i,ii,k,c,sm,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		c=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k%2)
			{
				c++;
				ex[c]=i;
			}
		}
		z=inf;
		for(ii=0;ii<2;ii++)
		{
			if(c==(n+!ii)/2)
			{
				sm=0;
				for(i=ii+1;i<=n;i+=2)
				{
					sm+=abs(i-ex[(i+1)/2]);
				}
				z=min(z,sm);
			}
		}
		if(z==inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}
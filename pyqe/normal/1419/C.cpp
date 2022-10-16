#include <bits/stdc++.h>

using namespace std;

long long n,d,ttl,inf=1e18;

int main()
{
	long long t,rr,i,k,l,z;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		ttl=0;
		bad=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			if(!i||k==l)
			{
				l=k;
			}
			else
			{
				l=-inf;
			}
			ttl+=k;
			bad|=k==d;
		}
		if(l==d)
		{
			z=0;
		}
		else if(bad||d*n==ttl)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}
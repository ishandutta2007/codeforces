#include <bits/stdc++.h>

using namespace std;

long long n,d,inf=1e18;

int main()
{
	long long t,rr,i,k,sm,mn,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		sm=0;
		mn=inf;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			if(k%d)
			{
				mn=min(mn,i);
				mx=i;
			}
		}
		if(mn==inf)
		{
			z=-1;
		}
		else
		{
			z=n;
			if(sm%d==0)
			{
				z-=min(mn,n+1-mx);
			}
		}
		printf("%lld\n",z);
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,k,mn,mx,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn=inf;
		mx=-inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			mn=min(mn,k);
			mx=max(mx,k);
		}
		if(mn==mx)
		{
			z=n;
		}
		else
		{
			z=1;
		}
		printf("%lld\n",z);
	}
}
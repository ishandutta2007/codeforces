#include <bits/stdc++.h>

using namespace std;

long long n,ttl,inf=1e18;

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		mx=-inf;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			ttl+=k;
			mx=max(mx,k);
		}
		if(mx>ttl-mx||(ttl-mx*2)%2)
		{
			printf("T\n");
		}
		else
		{
			printf("HL\n");
		}
	}
}
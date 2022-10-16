#include <bits/stdc++.h>

using namespace std;

long long n,ttl;

int main()
{
	long long t,rr,i,k,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		mx=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			ttl+=k;
			mx=max(mx,k);
		}
		printf("%lld\n",max(mx*(n-1),(ttl+n-2)/(n-1)*(n-1))-ttl);
	}
}
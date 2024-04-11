#include <bits/stdc++.h>

using namespace std;

long long n,ttl;

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		for(i=0;i<n;i++)
		{
			scanf("%lld",&k);
			ttl+=k;
		}
		k=ttl%n;
		printf("%lld\n",k*(n-k));
	}
}
#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,ttl;

int main()
{
	long long t,rr,i,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		mn=inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ttl+=k;
			mn=min(mn,k);
		}
		printf("%lld\n",ttl-mn*n);
	}
}
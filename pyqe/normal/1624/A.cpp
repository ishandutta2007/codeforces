#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n;

int main()
{
	long long t,rr,i,k,mn,mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		mn=inf;
		mx=-inf;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			mn=min(mn,k);
			mx=max(mx,k);
		}
		printf("%lld\n",mx-mn);
	}
}
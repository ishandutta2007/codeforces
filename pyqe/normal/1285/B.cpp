#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
	long long t,rr,i,k,ttl,sm,mx;
	bool bad;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		sm=0;
		mx=-1e18;
		bad=1;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ttl+=k;
			sm+=k;
			if(sm<=0)
			{
				sm=0;
				bad=0;
			}
			if(i!=n||!bad)
			{
				mx=max(mx,sm);
			}
			
		}
		if(ttl>mx)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
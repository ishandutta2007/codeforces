#include <bits/stdc++.h>

using namespace std;

long long n,ttl,inf=1e18;

int main()
{
	long long t,rr,i,u,k,sm,mn[2],mx;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		ttl=0;
		sm=0;
		mn[0]=0;
		mn[1]=inf;
		mx=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			ttl+=k*(i%2);
			u=!(i%2)*2-1;
			sm+=k*u;
			mn[i%2]=min(mn[i%2],sm);
			mx=max(mx,sm-mn[i%2]);
		}
		printf("%lld\n",ttl+mx);
	}
}
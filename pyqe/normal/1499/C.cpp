#include <bits/stdc++.h>

using namespace std;

long long n,inf=1e18;

int main()
{
	long long t,rr,i,ii,k,c[2],mn[2],sm,w,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			c[ii]=0;
			mn[ii]=inf;
		}
		z=inf;
		sm=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			sm+=k;
			c[i%2]++;
			mn[i%2]=min(mn[i%2],k);
			w=sm;
			for(ii=0;ii<2;ii++)
			{
				w+=mn[ii]*(n-c[ii]);
			}
			if(i-1)
			{
				z=min(z,w);
			}
		}
		printf("%lld\n",z);
	}
}
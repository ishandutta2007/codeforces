#include <bits/stdc++.h>

using namespace std;

long long n,ls[300069],dp[300069],sq[300069],inf=1e18;

int main()
{
	long long t,rr,i,k,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			ls[i]=0;
			dp[i]=1;
			sq[i]=inf;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			dp[k]=max(dp[k],i-ls[k]);
			ls[k]=i;
		}
		for(i=1;i<=n;i++)
		{
			dp[i]=max(dp[i],n+1-ls[i]);
			sq[dp[i]]=min(sq[dp[i]],i);
		}
		for(i=1;i<=n;i++)
		{
			if(i-1)
			{
				sq[i]=min(sq[i],sq[i-1]);
			}
			z=sq[i];
			if(z==inf)
			{
				z=-1;
			}
			printf("%lld%c",z," \n"[i==n]);
		}
	}
}
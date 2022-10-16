#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069],ls[200069],inf=1e18;

int main()
{
	long long t,rr,i,k,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			dp[i]=0;
			ls[i]=0;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			dp[k]+=ls[k]<i-1;
			ls[k]=i;
		}
		for(i=1;i<=n;i++)
		{
			dp[i]+=ls[i]<n;
		}
		mn=inf;
		for(i=1;i<=n;i++)
		{
			if(ls[i])
			{
				mn=min(mn,dp[i]);
			}
		}
		printf("%lld\n",mn);
	}
}
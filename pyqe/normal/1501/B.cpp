#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069];

int main()
{
	long long t,rr,i,k;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			dp[i]=i+1-k;
		}
		for(i=n-1;i;i--)
		{
			dp[i]=min(dp[i],dp[i+1]);
		}
		for(i=1;i<=n;i++)
		{
			printf("%lld%c",(long long)(dp[i]<=i)," \n"[i==n]);
		}
	}
}
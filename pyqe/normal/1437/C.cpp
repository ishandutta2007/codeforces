#include <bits/stdc++.h>

using namespace std;

long long n,a[269],dp[269][469],inf=1e18;

int main()
{
	long long t,rr,i,j,mn;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i++)
		{
			mn=inf;
			for(j=0;j<=n*2;j++)
			{
				dp[i][j]=mn+abs(j-a[i]);
				mn=min(mn,dp[i-1][j]);
			}
		}
		mn=inf;
		for(i=0;i<=n*2;i++)
		{
			mn=min(mn,dp[n][i]);
		}
		printf("%lld\n",mn);
	}
}
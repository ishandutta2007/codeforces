#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,d,a[50069],dp[50069][3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		scanf("%lld",&d);
		dp[0][0]=0;
		dp[0][1]=-inf;
		dp[0][2]=-inf;
		for(i=1;i<=n;i++)
		{
			a[i]-=d;
			dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
			dp[i][1]=dp[i-1][0]+1;
			dp[i][2]=-inf;
			if(i>=2&&a[i]+a[i-1]>=0)
			{
				dp[i][2]=dp[i-1][1]+1;
				if(i>=3&&a[i]+a[i-1]+a[i-2]>=0)
				{
					dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
				}
			}
		}
		printf("%lld\n",max({dp[n][0],dp[n][1],dp[n][2]}));
	}
}
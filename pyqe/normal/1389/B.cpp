#include <bits/stdc++.h>

using namespace std;

long long n,d,d2,a[100069],dp[100069][6],inf=1e18;

int main()
{
	long long t,rr,i,j,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&d,&d2);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=d2;j++)
			{
				dp[i][j]=dp[i-1][j]+a[i];
				if(j&&i<n)
				{
					dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i]+a[i+1]);
				}
			}
		}
		z=-inf;
		for(i=0;i<=d2;i++)
		{
			if(d+1-i*2>0)
			{
				z=max(z,dp[d+1-i*2][i]);
			}
		}
		printf("%lld\n",z);
	}
}
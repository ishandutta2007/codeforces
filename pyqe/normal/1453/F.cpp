#include <bits/stdc++.h>

using namespace std;

long long n,a[3069],pc[3069][3069],dp[3069][3069],inf=1e18;

int main()
{
	long long t,rr,i,j,w;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
			a[i]+=i;
			pc[i-1][i]=0;
			for(j=i-1;j;j--)
			{
				pc[j-1][i]=pc[j][i]+(a[j]>=i);
			}
		}
		dp[n][n+1]=0;
		for(i=n-1;i;i--)
		{
			dp[i][n+1]=inf;
			for(j=n;j>i;j--)
			{
				if(j<=a[i])
				{
					w=dp[j][a[i]+1]+pc[i][j];
				}
				else
				{
					w=inf;
				}
				dp[i][j]=min(dp[i][j+1],w);
			}
		}
		printf("%lld\n",dp[1][2]);
	}
}
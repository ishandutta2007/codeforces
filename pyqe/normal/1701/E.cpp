#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n[2],a[2][5069],dp[5069][5069];

int main()
{
	long long t,rr,i,j,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",n,n+1);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n[ii];i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'a';
			}
		}
		dp[0][0]=1;
		for(i=0;i<=n[0];i++)
		{
			for(j=!i;j<=n[1];j++)
			{
				dp[i][j]=inf;
				if(i)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j]+2);
				}
				if(i&&j&&a[0][i]==a[1][j])
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
				}
			}
		}
		dp[0][0]=0;
		for(i=0;i<=n[0];i++)
		{
			for(j=!i;j<=n[1];j++)
			{
				if(i&&j&&a[0][i]==a[1][j])
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				}
			}
		}
		for(i=0;i<=n[0];i++)
		{
			for(j=!i;j<=n[1];j++)
			{
				dp[i][j]=dp[i][j];
				if(i)
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
				}
				if(i&&j&&a[0][i]==a[1][j])
				{
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);
				}
			}
		}
		z=dp[n[0]][n[1]];
		if(z>=inf)
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}
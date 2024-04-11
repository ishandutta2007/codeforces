#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[1069][1069][2];
bitset<1069> a[1069];

int main()
{
	long long t,rr,i,j,ii,u;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld%lld",&n,&m,&d);
		for(i=0;i<=n+1;i++)
		{
			for(j=0;j<=m+1;j++)
			{
				for(ii=0;ii<2;ii++)
				{
					dp[i][j][ii]=0;
				}
			}
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='*';
				for(ii=0;ii<2;ii++)
				{
					u=!ii*2-1;
					dp[i][j][ii]=(dp[i-1][j-u][ii]+1)*a[i][j];
				}
			}
		}
		for(i=n;i;i--)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j][0]=min(dp[i][j][0],dp[i][j][1]);
				if(dp[i][j][0]<d+1)
				{
					dp[i][j][0]=0;
				}
				dp[i][j][1]=dp[i][j][0];
				for(ii=0;ii<2;ii++)
				{
					u=!ii*2-1;
					dp[i][j][ii]=max(dp[i][j][ii],dp[i+1][j+u][ii]-1);
				}
				if(a[i][j]&&!max(dp[i][j][0],dp[i][j][1]))
				{
					break;
				}
			}
			if(j<=m)
			{
				break;
			}
		}
		if(!i)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}
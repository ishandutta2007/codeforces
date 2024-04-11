#include <bits/stdc++.h>

using namespace std;

long long n,a[2][2069],ps[2][26][2069],dp[2069][2069],inf=1e18;

int main()
{
	long long t,rr,i,j,r,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf(" %c",&ch);
				a[ii][i]=ch-'a';
				for(j=0;j<26;j++)
				{
					ps[ii][j][i]=ps[ii][j][i-1];
				}
				ps[ii][a[ii][i]][i]++;
			}
		}
		dp[0][0]=0;
		for(i=0;i<=n;i++)
		{
			for(j=!i;j<=n;j++)
			{
				dp[i][j]=-inf;
				for(r=0;r<26;r++)
				{
					if(ps[0][r][i]>ps[1][r][j])
					{
						r=-1;
						break;
					}
				}
				if(r!=-1)
				{
					if(i)
					{
						dp[i][j]=max(dp[i][j],dp[i-1][j]);
					}
					if(j)
					{
						dp[i][j]=max(dp[i][j],dp[i][j-1]);
					}
					if(i&&j&&a[0][i]==a[1][j])
					{
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					}
				}
			}
		}
		if(dp[n][n]!=-inf)
		{
			z=n-dp[n][n];
		}
		else
		{
			z=-1;
		}
		printf("%lld\n",z);
	}
}
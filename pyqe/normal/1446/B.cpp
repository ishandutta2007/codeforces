#include <bits/stdc++.h>

using namespace std;

long long n[2],a[2][5069],dp[5069][5069];

int main()
{
	long long i,j,ii,z=0;
	char ch;
	
	scanf("%lld%lld",n,n+1);
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n[ii];i++)
		{
			scanf(" %c",&ch);
			a[ii][i]=ch-'a';
		}
	}
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			dp[i][j]=i+j;
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
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+4);
			}
			z=max(z,dp[i][j]-i-j);
		}
	}
	printf("%lld\n",z);
}
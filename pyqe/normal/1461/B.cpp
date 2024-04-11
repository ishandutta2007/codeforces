#include <bits/stdc++.h>

using namespace std;

long long n,m,dp[569][569],inf=1e18;
bitset<569> a[569];

int main()
{
	long long t,rr,i,j,r,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf(" %c",&ch);
				a[i][j]=ch=='*';
			}
		}
		for(i=1;i<=n+1;i++)
		{
			for(j=0;j<=m+1;j++)
			{
				dp[i][j]=0;
			}
		}
		z=0;
		for(i=n;i;i--)
		{
			for(j=1;j<=m;j++)
			{
				dp[i][j]=inf*a[i][j];
				for(r=-1;r<=1;r++)
				{
					dp[i][j]=min(dp[i][j],dp[i+1][j+r]+1);
				}
				z+=dp[i][j];
			}
		}
		printf("%lld\n",z);
	}
}
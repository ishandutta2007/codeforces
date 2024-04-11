#include <bits/stdc++.h>

using namespace std;

long long n,m,d,dp[169][69],inf=1e18;

int main()
{
	long long i,j,r,k,sm=0,mx;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=0;i<d;i++)
	{
		for(j=0;j<=m;j++)
		{
			dp[i][j]=-inf;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm=(sm+k)%d;
		for(j=m;j;j--)
		{
			mx=-inf;
			for(r=0;r<d;r++)
			{
				mx=max(mx,dp[r][j-1]+(sm+d-r)%d);
			}
			dp[sm][j]=max(dp[sm][j],mx);
		}
	}
	printf("%lld\n",dp[sm][m]);
}
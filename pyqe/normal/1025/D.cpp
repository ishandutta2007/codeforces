#include <bits/stdc++.h>

using namespace std;

int n,a[769];
bitset<769> spc[769],dp[769];

int main()
{
	int i,j,r;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		dp[i][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			spc[i][j]=__gcd(a[i],a[j])>1;
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<=n-i;j++)
		{
			for(r=j+1;r<=j+i;r++)
			{
				dp[j][j+i]=dp[j][j+i]||(spc[j][r]&&dp[r][j+i]&&dp[r][j+1]);
			}
			for(r=j;r<j+i;r++)
			{
				dp[j+i][j]=dp[j+i][j]||(spc[j+i][r]&&dp[r][j]&&dp[r][j+i-1]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		if(dp[i][n]&&dp[i][1])
		{
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
}
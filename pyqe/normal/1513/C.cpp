#include <bits/stdc++.h>

using namespace std;

const long long ma=2e5,dv=1e9+7;
long long n,d,dp[2][10],pc[10][200069];

int main()
{
	long long t,rr,i,j,r,z;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			dp[0][j]=j==i;
		}
		for(j=1;j<=ma;j++)
		{
			for(r=0;r<10;r++)
			{
				dp[1][r]=dp[0][(r+9)%10];
			}
			dp[1][1]=(dp[1][1]+dp[0][9])%dv;
			for(r=0;r<10;r++)
			{
				dp[0][r]=dp[1][r];
				pc[i][j]=(pc[i][j]+dp[0][r])%dv;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		z=0;
		for(;n;n/=10)
		{
			z=(z+pc[n%10][d])%dv;
		}
		printf("%lld\n",z);
	}
}
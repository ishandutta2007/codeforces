#include <bits/stdc++.h>

using namespace std;

const long long dv=998244353;

long long n,d,cb[269][269],pc[62569],dp[2][269];

inline long long tri(long long x)
{
	return x*(x-1)/2;
}

int main()
{
	long long i,j,r;
	
	scanf("%lld%lld",&n,&d);
	cb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=i;j++)
		{
			cb[i][j]=cb[i-1][j];
			if(j)
			{
				cb[i][j]=(cb[i][j]+cb[i-1][j-1])%dv;
			}
		}
	}
	dp[0][0]=1;
	for(i=1;i<=d;i++)
	{
		pc[0]=1;
		for(j=1;j<=n*n;j++)
		{
			pc[j]=pc[j-1]*(d+1-i)%dv;
		}
		for(j=0;j<n;j++)
		{
			for(r=0;r<=j;r++)
			{
				dp[1][j]=(dp[1][j]+dp[0][r]*cb[j][r]%dv*pc[tri(j-r)+(j-r)*r])%dv;
			}
		}
		for(j=0;j<n;j++)
		{
			dp[0][j]=dp[1][j];
			dp[1][j]=0;
		}
	}
	printf("%lld\n",dp[0][n-1]);
}
#include <bits/stdc++.h>

using namespace std;

long long n,m;
double d,dp[2069][2069];

int main()
{
	long long i,j;
	double z=0;
	
	scanf("%lld%lf%lld",&n,&d,&m);
	dp[0][0]=1;
	for(i=1;i<=m;i++)
	{
		for(j=0;j<=n;j++)
		{
			dp[i][min(j+1,n)]+=dp[i-1][j]*d;
			dp[i][j]+=dp[i-1][j]*((double)1-d);
		}
	}
	for(i=0;i<=n;i++)
	{
		z+=i*dp[m][i];
	}
	printf("%.20lf",z);
}
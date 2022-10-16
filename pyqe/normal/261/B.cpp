#include <bits/stdc++.h>

using namespace std;

long long n,d,ma=50,dp[69][2569],cb[69][69];

int main()
{
	long long i,j,r,k;
	double z=0;
	
	scanf("%lld",&n);
	dp[0][0]=1;
	cb[0][0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(j=i;j;j--)
		{
			for(r=i*ma;r>=k;r--)
			{
				dp[j][r]+=dp[j-1][r-k];
			}
			cb[i][j]=cb[i-1][j]+cb[i-1][j-1];
		}
		cb[i][0]=cb[i-1][0];
	}
	scanf("%lld",&d);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=d;j++)
		{
			z+=(double)dp[i][j]/cb[n][i];
		}
	}
	printf("%.10lf\n",z);
}
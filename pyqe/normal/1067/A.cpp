#include <bits/stdc++.h>

using namespace std;

long long n,ma=200,dp[2][2][269],ps[2][269],dv=998244353;

int main()
{
	long long i,j,ii,k,lb,rb;
	
	scanf("%lld",&n);
	dp[0][1][0]=1;
	for(i=0;i<=ma;i++)
	{
		ps[1][i]=1;
	}
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		if(k+1)
		{
			lb=k;
			rb=k;
		}
		else
		{
			lb=1;
			rb=ma;
		}
		for(j=lb;j<=rb;j++)
		{
			dp[1][0][j]=(ps[0][j-1]+ps[1][j-1])%dv;
			dp[1][1][j]=(ps[1][ma]+dv-ps[1][j-1]+dp[0][0][j])%dv;
		}
		for(ii=0;ii<2;ii++)
		{
			ps[ii][0]=0;
			for(j=0;j<=ma;j++)
			{
				dp[0][ii][j]=dp[1][ii][j];
				dp[1][ii][j]=0;
				if(j)
				{
					ps[ii][j]=(ps[ii][j-1]+dp[0][ii][j])%dv;
				}
			}
		}
	}
	printf("%lld\n",ps[1][ma]);
}
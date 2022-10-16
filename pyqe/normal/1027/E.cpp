#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[569][569],ps[2][569][569],dv=998244353;

int main()
{
	long long i,j,z=0;
	
	scanf("%lld%lld",&n,&d);
	dp[0][0]=1;
	for(i=0;i<=n;i++)
	{
		ps[0][0][i]=1;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j<=i)
			{
				dp[i][j]=(ps[0][i-j][j-1]+ps[1][i-1][j]+dv-ps[1][max(i-j-1,0ll)][j])%dv;
			}
			ps[0][i][j]=(ps[0][i][j-1]+dp[i][j])%dv;
			ps[1][i][j]=(ps[1][i-1][j]+dp[i][j])%dv;
		}
	}
	for(i=1;i<=n;i++)
	{
		z=(z+dp[n][i]*ps[0][n][min((d-1)/i,n)])%dv;
	}
	z=z*2%dv;
	printf("%lld\n",z);
}
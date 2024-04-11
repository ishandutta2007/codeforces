#include <bits/stdc++.h>

using namespace std;

long long n,ln,lb,rb,dp[2069][2069];

int main()
{
	long long i,j,ii,k,sm=0,z=-1e18;
	
	scanf("%lld%lld%lld%lld",&n,&ln,&lb,&rb);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		sm=(sm+k)%ln;
		for(j=0;j<=i;j++)
		{
			dp[i][j]=-1e18;
			for(ii=0;ii<2;ii++)
			{
				if(j-ii+1&&j-ii<=i-1)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-ii]);
				}
			}
			k=(sm+ln*j-j)%ln;
			dp[i][j]+=k>=lb&&k<=rb;
			if(i==n)
			{
				z=max(z,dp[i][j]);
			}
		}
	}
	printf("%lld\n",z);
}
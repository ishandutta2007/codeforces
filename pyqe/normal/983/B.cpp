#include <bits/stdc++.h>

using namespace std;

long long n,dp[5069][5069],sq[5069][5069];

int main()
{
	long long t,rr,i,j,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&dp[i][i]);
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j;j--)
		{
			if(j<i)
			{
				dp[j][i]=dp[j][i-1]^dp[j+1][i];
			}
			sq[j][i]=max(max(sq[j][i-1],sq[j+1][i]),dp[j][i]);
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&k,&l);
		printf("%lld\n",sq[k][l]);
	}
}
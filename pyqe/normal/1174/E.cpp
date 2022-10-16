#include <bits/stdc++.h>

using namespace std;

long long n,lgn,a[21][2],dp[21][2],dv=1e9+7;

int main()
{
	long long i,j,ii,iii,k;
	
	scanf("%lld",&n);
	for(k=n;k>1;k/=2,lgn++);
	for(i=0;i<=lgn+1;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			a[i][ii]=max(a[i-1][0]*(2+ii),1ll);
		}
	}
	for(ii=0;ii<2;ii++)
	{
		dp[lgn][ii]=n/a[lgn][ii];
	}
	for(i=2;i<=n;i++)
	{
		for(j=0;j<=lgn;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[j][ii]=dp[j][ii]*max(n/a[j][ii]-i+1,0ll)%dv;
				for(iii=ii;iii<2;iii++)
				{
					dp[j][ii]=(dp[j][ii]+dp[j+1][iii]*(n/a[j][ii]-n/a[j+1][iii]))%dv;
				}
			}
		}
	}
	printf("%lld\n",dp[0][0]);
}
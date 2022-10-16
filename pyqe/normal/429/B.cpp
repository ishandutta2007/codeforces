#include <bits/stdc++.h>

using namespace std;

long long n,m,a[1069][1069],dp[4][1069][1069];

int main()
{
	long long i,j,ii,iii,ui,uj,sm,z=-1e18;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(ii=0;ii<4;ii++)
	{
		ui=!(ii/2)*2-1;
		uj=!(ii%2)*2-1;
		for(i=1+(n-1)*(ii/2);i!=(n+1)*!(ii/2);i+=ui)
		{
			for(j=1+(m-1)*(ii%2);j!=(m+1)*!(ii%2);j+=uj)
			{
				dp[ii][i][j]=max(dp[ii][i-ui][j],dp[ii][i][j-uj])+a[i][j];
			}
		}
	}
	for(i=2;i<=n-1;i++)
	{
		for(j=2;j<=m-1;j++)
		{
			for(iii=0;iii<2;iii++)
			{
				sm=0;
				for(ii=0;ii<4;ii++)
				{
					ui=!(ii/2)*2-1;
					uj=!(ii%2)*2-1;
					sm+=dp[ii][i-ui*((ii&&(3-ii))^iii)][j-uj*!((ii&&(3-ii))^iii)];
				}
				z=max(z,sm);
			}
		}
	}
	printf("%lld\n",z);
}
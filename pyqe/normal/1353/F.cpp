#include <bits/stdc++.h>

using namespace std;

long long n,m,mxn=100,a[169][169],dp[169][169],inf=1e18;

int main()
{
	long long t,rr,i,j,ii,jj,k,z;
	
	scanf("%lld",&t);
	for(i=0;i<=mxn;i++)
	{
		for(j=0;j<=mxn;j++)
		{
			dp[i][j]=inf;
		}
	}
	dp[0][1]=0;
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&a[i][j]);
			}
		}
		z=inf;
		for(ii=1;ii<=n;ii++)
		{
			for(jj=1;jj<=m;jj++)
			{
				k=a[ii][jj]-ii-jj;
				for(i=1;i<=n;i++)
				{
					for(j=1;j<=m;j++)
					{
						dp[i][j]=max(min(dp[i-1][j],dp[i][j-1])+a[i][j]-k-i-j,inf*(a[i][j]<k+i+j));
					}
				}
				z=min(z,dp[n][m]);
			}
		}
		printf("%lld\n",z);
	}
}
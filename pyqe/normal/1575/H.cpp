#include <bits/stdc++.h>

using namespace std;

const long long inf=1e18;
long long n,m,faf[569],pr[569][2],dp[2][569][569];
bitset<569> aa,a;

int main()
{
	long long i,j,r,ii,tg,tg2,z;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		aa[i]=ch-'0';
	}
	faf[0]=-1;
	for(i=1;i<=m;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'0';
		for(j=faf[i-1];j+1&&a[j+1]!=a[i];j=faf[j]);
		faf[i]=j+1;
	}
	for(i=0;i<m;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(j=i;j+1&&a[j+1]!=ii;j=faf[j]);
			pr[i][ii]=j+1;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=n-m+1;i++)
		{
			for(j=0;j<m;j++)
			{
				dp[ii][i][j]=inf;
			}
		}
	}
	dp[0][0][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n-m+1;j++)
		{
			for(r=0;r<m;r++)
			{
				for(ii=0;ii<2;ii++)
				{
					tg=pr[r][ii];
					tg2=tg;
					if(tg==m)
					{
						tg2=faf[tg];
					}
					dp[1][j+tg/m][tg2]=min(dp[1][j+tg/m][tg2],dp[0][j][r]+(aa[i]!=ii));
				}
			}
		}
		for(j=0;j<=n-m+1;j++)
		{
			for(r=0;r<m;r++)
			{
				dp[0][j][r]=dp[1][j][r];
				dp[1][j][r]=inf;
			}
		}
	}
	for(i=0;i<=n-m+1;i++)
	{
		z=inf;
		for(j=0;j<m;j++)
		{
			z=min(z,dp[0][i][j]);
		}
		if(z>n)
		{
			z=-1;
		}
		printf("%lld%c",z," \n"[i==n-m+1]);
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n,m,aa[2069],a[569],faf[569],tg[569][26],dp[2][2069][2],sq[2069],inf=1e18;

int main()
{
	long long i,j,r,ii,u,k;
	string s;
	
	cin>>s;
	n=s.length();
	for(i=1;i<=n;i++)
	{
		aa[i]=s[i-1]-'a';
	}
	cin>>s;
	m=s.length();
	for(i=1;i<=m;i++)
	{
		a[i]=s[i-1]-'a';
	}
	faf[0]=-1;
	for(i=1;i<=m;i++)
	{
		for(j=faf[i-1];j+1&&a[j+1]!=a[i];j=faf[j]);
		faf[i]=j+1;
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<26;j++)
		{
			for(r=i;r+1&&a[r+1]!=j;r=faf[r]);
			tg[i][j]=r+1;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			u=!ii*2-1;
			dp[0][i][ii]=inf*u;
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[1][j][ii]=dp[0][j][ii]+1;
			}
		}
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				k=j/m*m+tg[j%m][aa[i]];
				dp[1][k][ii]=min(dp[1][k][ii]*u,dp[0][j][ii]*u)*u;
			}
		}
		for(j=0;j<=n;j++)
		{
			for(ii=0;ii<2;ii++)
			{
				dp[0][j][ii]=dp[1][j][ii];
			}
		}
	}
	for(i=0;i<=n;i++)
	{
		for(j=dp[0][i][0];j<=dp[0][i][1];j++)
		{
			sq[j]=i/m;
		}
	}
	for(i=0;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
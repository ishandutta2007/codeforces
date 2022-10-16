#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2069][2069],dp[2069][2069],sq[4069],inf=1e18;
bitset<2069> spc[2069];

int main()
{
	long long i,j,k,mx=0,mn;
	char ch;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<=n;i++)
	{
		dp[0][i]=inf;
		dp[i][0]=inf;
	}
	dp[0][1]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf(" %c",&ch);
			a[i][j]=ch-'a';
			dp[i][j]=min(dp[i-1][j],dp[i][j-1])+!!a[i][j];
			if(dp[i][j]<=d)
			{
				mx=max(mx,i+j-1);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		k=mx-i+1;
		if(k>0&&k<=n)
		{
			spc[k][i]=dp[k][i]<=d;
		}
	}
	if(!mx)
	{
		spc[0][1]=1;
	}
	for(i=mx+1;i<=n*2-1;i++)
	{
		mn=inf;
		for(j=1;j<=n;j++)
		{
			k=i-j+1;
			if(k>0&&k<=n&&(spc[k-1][j]||spc[k][j-1]))
			{
				mn=min(mn,a[k][j]);
			}
		}
		sq[i]=mn;
		for(j=1;j<=n;j++)
		{
			k=i-j+1;
			if(k>0&&k<=n&&(spc[k-1][j]||spc[k][j-1])&&a[k][j]==mn)
			{
				spc[k][j]=1;
			}
		}
	}
	for(i=1;i<=n*2-1;i++)
	{
		printf("%c",(char)(sq[i]+'a'));
	}
	printf("\n");
}
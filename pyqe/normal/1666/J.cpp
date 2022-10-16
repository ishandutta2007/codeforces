#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,am[269][269],ps[269][269],pr[269];
pair<long long,long long> dp[269][269];

long long trv(long long lb,long long rb)
{
	if(lb<=rb)
	{
		long long e=dp[lb][rb].sc;
		
		pr[trv(lb,e-1)]=e;
		pr[trv(e+1,rb)]=e;
		return e;
	}
	else
	{
		return 0;
	}
}

int main()
{
	long long i,j,r,w;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%lld",&am[i][j]);
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+am[i][j];
		}
	}
	for(i=0;i<=n;i++)
	{
		dp[i+1][i].fr=0;
		for(j=i;j;j--)
		{
			dp[j][i].fr=inf;
			for(r=j;r<=i;r++)
			{
				w=dp[j][r-1].fr+dp[r+1][i].fr;
				w+=ps[r-1][j-1]-ps[j-1][j-1];
				w+=ps[r-1][n]-ps[j-1][n]-ps[r-1][r-1]+ps[j-1][r-1];
				w+=ps[i][r]-ps[r][r];
				w+=ps[i][n]-ps[r][n]-ps[i][i]+ps[r][i];
				dp[j][i]=min(dp[j][i],{w,r});
			}
		}
	}
	trv(1,n);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",pr[i]," \n"[i==n]);
	}
}
#include <bits/stdc++.h>

using namespace std;

long long n[3],a[3][269],dp[269][269][269],inf=1e18;

long long bf(long long x,long long x2,long long x3)
{
	if(dp[x][x2][x3]==-1)
	{
		long long i,ii,k,w,p[3]={x,x2,x3};
		
		dp[x][x2][x3]=0;
		for(i=0;i<3;i++)
		{
			w=1;
			for(ii=0;ii<2;ii++)
			{
				k=(i+ii)%3;
				p[k]++;
				w*=a[k][p[k]];
			}
			if(w)
			{
				dp[x][x2][x3]=max(dp[x][x2][x3],bf(p[0],p[1],p[2])+w);
			}
			for(ii=0;ii<2;ii++)
			{
				k=(i+ii)%3;
				p[k]--;
			}
		}
	}
	return dp[x][x2][x3];
}

int main()
{
	long long i,j,r;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",n+i);
	}
	for(i=0;i<3;i++)
	{
		for(j=1;j<=n[i];j++)
		{
			scanf("%lld",&a[i][j]);
		}
		sort(a[i]+1,a[i]+n[i]+1,greater<long long>());
	}
	for(i=0;i<=n[0];i++)
	{
		for(j=0;j<=n[1];j++)
		{
			for(r=0;r<=n[2];r++)
			{
				dp[i][j][r]=-1;
			}
		}
	}
	printf("%lld\n",bf(0,0,0));
}
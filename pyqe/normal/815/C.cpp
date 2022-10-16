#include <bits/stdc++.h>

using namespace std;

long long n,d,a[5069][2],sbt[5069],dp[5069][2][5069],tmp[5069],inf=1e18;
vector<long long> al[5069];

void dfs(long long x)
{
	long long i,j,r,ii,sz=al[x].size(),l;
	
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		for(j=0;j<=sbt[x]+sbt[l];j++)
		{
			tmp[j]=inf;
		}
		for(ii=0;ii<2;ii++)
		{
			for(j=0;j<=sbt[x];j++)
			{
				for(r=0;r<=sbt[l];r++)
				{
					tmp[j+r]=min(tmp[j+r],dp[x][ii][j]+dp[l][ii][r]);
				}
			}
			for(j=0;j<=sbt[x]+sbt[l];j++)
			{
				dp[x][ii][j]=tmp[j];
			}
		}
		sbt[x]+=sbt[l];
	}
	sbt[x]++;
	dp[x][0][sbt[x]]=inf;
	for(i=sbt[x];i;i--)
	{
		for(ii=0;ii<2;ii++)
		{
			dp[x][ii][i]=min(dp[x][0][i],dp[x][ii][i-1]+a[x][ii]);
		}
	}
	dp[x][1][0]=0;
}

int main()
{
	long long i,ii,k,z;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			scanf("%lld",&a[i][ii]);
		}
		a[i][1]=a[i][0]-a[i][1];
		if(i-1)
		{
			scanf("%lld",&k);
			al[k].push_back(i);
		}
	}
	dfs(1);
	z=upper_bound(dp[1][1],dp[1][1]+n+1,d)-dp[1][1]-1;
	printf("%lld\n",z);
}
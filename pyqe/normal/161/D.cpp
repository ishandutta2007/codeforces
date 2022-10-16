#include <bits/stdc++.h>

using namespace std;

long long n,d,dp[50069][569],z=0;
vector<long long> al[50069];
bitset<50069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x][0]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			for(j=d;j;j--)
			{
				dp[l][j]=dp[l][j-1];
			}
			dp[l][0]=0;
			for(j=0;j<=d;j++)
			{
				z+=dp[x][j]*dp[l][d-j];
			}
			for(j=0;j<=d;j++)
			{
				dp[x][j]+=dp[l][j];
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld\n",z);
}
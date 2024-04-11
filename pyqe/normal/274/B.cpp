#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],dp[100069][2];
vector<long long> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,ii,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			dp[l][a[l]-a[x]<0]+=abs(a[l]-a[x]);
			for(ii=0;ii<2;ii++)
			{
				dp[x][ii]=max(dp[x][ii],dp[l][ii]);
			}
		}
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	dfs(1);
	printf("%lld\n",dp[1][0]+dp[1][1]+abs(a[1]+dp[1][0]-dp[1][1]));
}
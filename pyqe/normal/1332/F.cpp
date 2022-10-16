#include <bits/stdc++.h>

using namespace std;

long long n,dp[300069][3],dv=998244353;
vector<long long> al[300069];
bitset<300069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<3;i++)
	{
		dp[x][i]=1;
	}
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			dp[x][0]=dp[x][0]*(dp[l][0]*2+dp[l][1]*2+dp[l][2]*3)%dv;
			dp[x][1]=dp[x][1]*(dp[l][0]*2+dp[l][1]+dp[l][2]*2)%dv;
			dp[x][2]=dp[x][2]*(dp[l][0]+dp[l][1]+dp[l][2])%dv;
		}
	}
	dp[x][0]=(dp[x][0]+dv-dp[x][2])%dv;
	dp[x][1]=(dp[x][1]+dv-dp[x][2])%dv;
}

int main()
{
	long long i,k,l,z=dv-1;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=0;i<3;i++)
	{
		z=(z+dp[1][i])%dv;
	}
	printf("%lld\n",z);
}
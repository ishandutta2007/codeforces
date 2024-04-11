#include <bits/stdc++.h>

using namespace std;

long long n,d,a[1069],dp[1069][1069];
vector<long long> al[1069],cd[1069];
bitset<1069> vtd;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l,k,mx;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			cd[x].push_back(l);
		}
	}
	sz=cd[x].size();
	for(i=d;i>=0;i--)
	{
		dp[x][i]=dp[x][i+1];
		mx=0;
		k=0;
		for(j=0;j<sz;j++)
		{
			l=cd[x][j];
			k+=dp[l][max(i-1,d-i)];
			if(i)
			{
				mx=max(mx,dp[l][i-1]-dp[l][max(i-1,d-i)]);
			}
		}
		if(i)
		{
			k+=mx;
		}
		else
		{
			k+=a[x];
		}
		dp[x][i]=max(dp[x][i],k);
	}
}

int main()
{
	long long i,k,l;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	printf("%lld\n",dp[1][0]);
}
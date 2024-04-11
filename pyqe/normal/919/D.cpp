#include <bits/stdc++.h>

using namespace std;

long long n,m,a[300069],dp[300069][26],z=0;
vector<long long> al[300069];
bitset<300069> vtd,vtd2;

void dfs(long long x)
{
	long long i,j,sz=al[x].size(),l;
	
	vtd[x]=1;
	vtd2[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
		else if(vtd2[l])
		{
			printf("-1\n");
			exit(0);
		}
		for(j=0;j<26;j++)
		{
			dp[x][j]=max(dp[x][j],dp[l][j]);
		}
	}
	vtd2[x]=0;
	dp[x][a[x]]++;
	z=max(z,dp[x][a[x]]);
}

int main()
{
	long long i,k,l;
	char ch;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf(" %c",&ch);
		a[i]=ch-'a';
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			dfs(i);
		}
	}
	printf("%lld\n",z);
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],pr[100069],dp[100069];
vector<long long> al[100069];
bitset<100069> vtd;

void bd(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			bd(l);
			dp[x]+=dp[l]+(a[x]!=a[l]);
		}
	}
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,sm=dp[1]-dp[x]-(pr[x]&&a[x]!=a[pr[x]]);
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			sm+=dp[l];
		}
	}
	if(!sm)
	{
		printf("YES\n%lld\n",x);
		exit(0);
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
	bd(1);
	vtd.reset();
	dfs(1);
	printf("NO\n");
}
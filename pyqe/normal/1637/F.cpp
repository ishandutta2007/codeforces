#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

const long long inf=1e18;
long long n,nn,a[200069],dp[200069],dp2[200069],as[200069];
vector<long long> al[200069];
bitset<200069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	dp[x]=0;
	dp2[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			dp[x]+=dp[l];
			dp2[x]=max(dp2[x],dp2[l]);
		}
	}
	if(!dp[x])
	{
		dp[x]=a[x];
	}
	else
	{
		dp[x]+=max(a[x]-dp2[x],0ll);
	}
	dp2[x]=max(dp2[x],a[x]);
}

int main()
{
	long long i,k,l,e,sz,z=0;
	pair<long long,long long> mxe={-inf,-1};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mxe=max(mxe,{a[i],i});
	}
	e=mxe.sc;
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(e);
	nn=1;
	as[1]=a[e];
	sz=al[e].size();
	for(i=0;i<sz;i++)
	{
		l=al[e][i];
		z+=dp[l];
		nn++;
		as[nn]=a[e]-dp2[l];
	}
	sort(as+1,as+nn+1);
	printf("%lld\n",z+as[1]+as[2]);
}
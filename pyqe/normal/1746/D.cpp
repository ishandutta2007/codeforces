#include <bits/stdc++.h>

using namespace std;

long long n,d,pr[200069],a[200069],rm[200069],dp[200069],z;
vector<long long> al[200069];

void dfs(long long x,long long cw)
{
	long long i,sz=al[x].size(),l;
	
	z+=a[x]*cw;
	if(sz)
	{
		rm[x]=cw%sz;
		for(i=0;i<sz;i++)
		{
			l=al[x][i];
			dfs(l,cw/sz);
		}
	}
}

void dfs2(long long x)
{
	long long i,sz=al[x].size(),l;
	vector<long long> v;
	
	if(sz)
	{
		for(i=0;i<sz;i++)
		{
			l=al[x][i];
			dfs2(l);
			v.push_back(dp[l]);
		}
		sort(v.begin(),v.end(),greater<long long>());
		for(i=0;i<rm[x];i++)
		{
			z+=v[i];
		}
		dp[x]=v[rm[x]]+a[x];
	}
	else
	{
		dp[x]=a[x];
	}
}

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&d);
		for(i=1;i<=n;i++)
		{
			al[i].clear();
		}
		for(i=2;i<=n;i++)
		{
			scanf("%lld",pr+i);
			al[pr[i]].push_back(i);
		}
		for(i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		z=0;
		dfs(1,d);
		dfs2(1);
		printf("%lld\n",z);
	}
}
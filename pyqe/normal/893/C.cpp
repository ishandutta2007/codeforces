#include <bits/stdc++.h>

using namespace std;

long long n,m,a[100069],mn,inf=1e18;
vector<long long> al[100069];
bool vtd[100069];

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	mn=min(mn,a[x]);
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
		}
	}
}

int main()
{
	long long i,k,l,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	for(i=1;i<=n;i++)
	{
		if(!vtd[i])
		{
			mn=inf;
			dfs(i);
			z+=mn;
		}
	}
	printf("%lld\n",z);
}
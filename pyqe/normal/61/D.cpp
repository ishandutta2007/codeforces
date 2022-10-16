#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,cdis=0,mx=-1e18;
vector<pair<long long,long long>> al[100069];
bitset<100069> vtd;

void dfs(long long x)
{
	long long i,sz=al[x].size(),l,w;
	
	vtd[x]=1;
	mx=max(mx,cdis);
	for(i=0;i<sz;i++)
	{
		l=al[x][i].fr;
		w=al[x][i].sc;
		if(!vtd[l])
		{
			cdis+=w;
			dfs(l);
			cdis-=w;
		}
	}
}

int main()
{
	long long i,k,l,w,z=0;
	
	scanf("%lld",&n);
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		al[k].push_back({l,w});
		al[l].push_back({k,w});
		z+=w;
	}
	dfs(1);
	printf("%lld\n",z*2-mx);
}
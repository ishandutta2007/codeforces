#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,a[100069],pr[100069],z=0,dv=1e9+7;
vector<long long> al[100069];
bitset<100069> vtd;
multiset<pair<long long,long long>> ms[100069];
multiset<pair<long long,long long>>::iterator it;

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,c;
	multiset<pair<long long,long long>> tmp;
	
	if(pr[x])
	{
		for(it=ms[pr[x]].begin();it!=ms[pr[x]].end();it++)
		{
			tmp.insert({__gcd((*it).fr,a[x]),(*it).sc});
		}
	}
	tmp.insert({a[x],1});
	c=0;
	for(it=tmp.begin();it!=tmp.end();)
	{
		k=(*it).fr;
		l=(*it).sc;
		c+=l;
		it++;
		if(it==tmp.end()||(*it).fr!=k)
		{
			ms[x].insert({k,c});
			z=(z+k*c)%dv;
			c=0;
		}
	}
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			pr[l]=x;
			dfs(l);
		}
	}
	
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
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
	printf("%lld\n",z);
}
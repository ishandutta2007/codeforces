#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[300069],dsu[300069],cc[300069],sq[300069];
vector<pair<long long,long long>> al[300069];
multiset<pair<long long,long long>> ms;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jo(long long x,long long y)
{
	long long i,sz;
	
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	sz=al[y].size();
	for(i=0;i<sz;i++)
	{
		al[x].push_back(al[y][i]);
	}
	a[x]+=a[y]-d;
	cc[x]+=cc[y];
	dsu[y]=x;
}

int main()
{
	long long i,k,l,sz,sm=0;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sm+=a[i];
		ms.insert({-a[i],i});
		dsu[i]=i;
		cc[i]=1;
	}
	if(sm<d*(n-1))
	{
		printf("NO\n");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back({l,i});
		al[l].push_back({k,i});
	}
	for(i=1;i<=n-1;i++)
	{
		k=ms.begin()->sc;
		sz=al[k].size();
		for(;fd(al[k][sz-1].fr)==k;al[k].pop_back(),sz--);
		l=fd(al[k][sz-1].fr);
		sq[i]=al[k][sz-1].sc;
		ms.erase(ms.begin());
		ms.erase({-a[l],l});
		jo(k,l);
		ms.insert({-a[fd(k)],fd(k)});
	}
	printf("YES\n");
	for(i=1;i<=n-1;i++)
	{
		printf("%lld\n",sq[i]);
	}
}
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d,a[100069],wg[100069],dsu[100069],cc[100069],sm[100069],inf=1e18;
vector<long long> al[100069];
multiset<pair<long long,long long>> ms[100069];

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void ins2(long long x,long long w,long long ww)
{
	multiset<pair<long long,long long>>::iterator it=ms[x].lower_bound({w,0});
	
	if(it!=ms[x].end()&&it->fr==w)
	{
		ww+=it->sc;
		ms[x].erase(it);
	}
	ms[x].insert({w,ww});
}

void jo(long long x,long long y)
{
	multiset<pair<long long,long long>>::iterator it;
	
	x=fd(x);
	y=fd(y);
	if(cc[x]<cc[y])
	{
		swap(x,y);
	}
	for(it=ms[y].begin();it!=ms[y].end();it++)
	{
		ins2(x,it->fr,it->sc);
	}
	sm[x]+=sm[y];
	cc[x]+=cc[y];
	dsu[y]=x;
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),k,l,w,ww;
	multiset<pair<long long,long long>>::iterator it;
	
	dsu[x]=x;
	cc[x]=0;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		dfs(l);
		jo(x,l);
	}
	ins2(fd(x),a[x],wg[x]);
	for(it=ms[fd(x)].upper_bound({a[x],inf});it!=ms[fd(x)].end()&&wg[x];)
	{
		k=it->fr;
		w=it->sc;
		ww=min(w,wg[x]);
		w-=ww;
		wg[x]-=ww;
		it++;
		ms[fd(x)].erase(prev(it));
		if(w)
		{
			ms[fd(x)].insert({k,w});
		}
	}
	sm[fd(x)]+=wg[x];
	cc[fd(x)]++;
}

int main()
{
	long long i,k,l,w;
	
	scanf("%lld%lld%lld",&n,&m,&d);
	for(i=2;i<=n;i++)
	{
		scanf("%lld",&k);
		al[k].push_back(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&k,&l,&w);
		a[k]=l;
		wg[k]=w;
	}
	dfs(1);
	printf("%lld\n",sm[fd(1)]);
}
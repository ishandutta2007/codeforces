#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,dsu[100069],cd[100069],mx[100069],sm[100069],sq[100069];
vector<long long> al[100069];
bitset<100069> vtd;
multiset<pair<long long,long long>> ms[100069];
multiset<pair<long long,long long>>::iterator it,et;

long long fd(long long x)
{
	if(dsu[x]!=x)
	{
		dsu[x]=fd(dsu[x]);
	}
	return dsu[x];
}

void jn(long long x,long long y)
{
	long long k,l,p[2]={fd(x),fd(y)},e;
	pair<long long,long long> mne=min(mp(cd[p[0]],0),{cd[p[1]],1});
	
	e=mne.sc;
	cd[p[!e]]+=cd[p[e]];
	for(it=ms[p[e]].begin();it!=ms[p[e]].end();it++)
	{
		k=(*it).fr;
		l=(*it).sc;
		et=ms[p[!e]].lower_bound({k,0});
		if(et!=ms[p[!e]].end()&&(*et).fr==k)
		{
			l+=(*et).sc;
			ms[p[!e]].erase(et);
		}
		ms[p[!e]].insert({k,l});
		if(l>mx[p[!e]])
		{
			mx[p[!e]]=l;
			sm[p[!e]]=0;
		}
		if(l==mx[p[!e]])
		{
			sm[p[!e]]+=k;
		}
	}
	dsu[p[e]]=p[!e];
}

void dfs(long long x)
{
	long long i,sz=al[x].size(),l;
	
	vtd[x]=1;
	for(i=0;i<sz;i++)
	{
		l=al[x][i];
		if(!vtd[l])
		{
			dfs(l);
			jn(x,l);
		}
	}
	sq[x]=sm[fd(x)];
}

int main()
{
	long long i,k,l;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		dsu[i]=i;
		cd[i]=1;
		ms[i].insert({k,1});
		mx[i]=1;
		sm[i]=k;
	}
	for(i=0;i<n-1;i++)
	{
		scanf("%lld%lld",&k,&l);
		al[k].push_back(l);
		al[l].push_back(k);
	}
	dfs(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==n]);
	}
}
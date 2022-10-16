#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,m,d[2],pr[269],sz=0,mx,e1,e2;
bool bad;
bitset<269> vtd;
pair<pair<long long,long long>,pair<long long,long long>> a[50069];
multiset<pair<long long,long long>> al[269];
multiset<long long> ms;
multiset<long long>::iterator it;
stack<pair<long long,long long>> prv;

long long fd(long long x)
{
	if(pr[x]!=x)
	{
		pr[x]=fd(pr[x]);
	}
	return pr[x];
}

void dfs(long long x)
{
	long long l,w;
	bool alr=0;
	multiset<pair<long long,long long>>::iterator it2;
	
	vtd[x]=1;
	for(it2=al[x].begin();it2!=al[x].end();it2++)
	{
		l=(*it2).fr;
		w=(*it2).sc;
		if(vtd[l])
		{
			if(!prv.empty()&&mp(l,w)!=prv.top())
			{
				alr=1;
			}
			if(alr)
			{
				mx=-1e18;
				bad=1;
			}
			alr=1;
		}
		else
		{
			prv.push({x,w});
			dfs(l);
			prv.pop();
		}
		if(bad)
		{
			if(w>mx)
			{
				mx=w;
				e1=x;
				e2=l;
			}
			vtd[x]=0;
			return;
		}
	}
	vtd[x]=0;
}

int main()
{
	long long i,j,k,l,w1,w2,mn=4e18;
	
	scanf("%lld%lld%lld%lld",&n,&m,d,d+1);
	for(i=1;i<=n;i++)
	{
		pr[i]=i;
	}
	for(i=0;i<m;i++)
	{
		scanf("%lld%lld%lld%lld",&a[i].sc.fr,&a[i].sc.sc,&a[i].fr.fr,&a[i].fr.sc);
	}
	sort(a,a+m);
	for(i=0;i<m;i++)
	{
		k=a[i].sc.fr;
		l=a[i].sc.sc;
		w1=a[i].fr.fr;
		w2=a[i].fr.sc;
		al[k].insert({l,w2});
		al[l].insert({k,w2});
		ms.insert(w2);
		sz++;
		if(fd(k)!=fd(l))
		{
			pr[fd(l)]=fd(k);
		}
		else
		{
			bad=0;
			dfs(k);
			al[e1].erase(al[e1].find({e2,mx}));
			al[e2].erase(al[e2].find({e1,mx}));
			ms.erase(ms.find(mx));
			sz--;
		}
		if(sz==n-1)
		{
			it=ms.end();
			it--;
			mn=min(mn,d[0]*w1+d[1]**it);
		}
	}
	if(mn==4000000000000000000)
	{
		mn=-1;
	}
	printf("%lld\n",mn);
}
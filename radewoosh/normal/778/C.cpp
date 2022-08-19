#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

const int nax=300*1007;
const long long mod1=1000*1000*1000+9;
const long long mod2=1000*1000*1000+7;
const long long h=100*1000+3;

int n;

vector <pair <int,int> > graf[nax];

int w;

multiset < pair <long long,long long> > *trz[nax];
multiset < pair <long long,long long> >::iterator it;

pair <int,int> wyn[nax];

long long wtu1[nax];
long long wtu2[nax];
long long sum1[nax];
long long sum2[nax];

inline long long dod1(long long a, long long b)
{
	a+=b;
	if (a>=mod1)
		a-=mod1;
	if (a>=mod1)
		a%=mod1;
	return a;
}

inline long long dod2(long long a, long long b)
{
	a+=b;
	if (a>=mod2)
		a-=mod2;
	if (a>=mod2)
		a%=mod2;
	return a;
}

inline pair <long long,long long> dod(pair <long long,long long> a, pair <long long,long long> b)
{
	return {dod1(a.first, b.first), dod2(a.second, b.second)};
}

bool mniej(int a, int b)
{
	return (trz[a]->size())>(trz[b]->size());
}

void dfs1(int v, int oj, int odl, long long pot1, long long pot2)
{
	w=max(w, odl);
	vector <int> dzie;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i].first==oj)
			continue;
		dzie.push_back(graf[v][i].first);
		wtu1[graf[v][i].first]=(pot1*graf[v][i].second)%mod1;
		wtu2[graf[v][i].first]=(pot2*graf[v][i].second)%mod2;
		sum1[graf[v][i].first]=dod1(sum1[v], wtu1[graf[v][i].first]);
		sum2[graf[v][i].first]=dod2(sum2[v], wtu2[graf[v][i].first]);
		dfs1(graf[v][i].first, v, odl+1, (pot1*h)%mod1, (pot2*h)%mod2);
	}
	if (dzie.empty())
	{
		trz[v]=new multiset < pair <long long,long long> >;
		trz[v]->insert({sum1[v], sum2[v]});
		return;
	}
	sort(dzie.begin(), dzie.end(), mniej);
	int x=dzie[0];
	multiset < pair <long long,long long> > * ten=trz[x];
	debug() << imie(v);
	debug() << dzie;
	for (int i=1; i<(int)dzie.size(); i++)
	{
		int u=dzie[i];
		pair <long long, long long> dodod;
		dodod={mod1-wtu1[u], mod2-wtu2[u]};
		dodod=dod(dodod, {wtu1[x], wtu2[x]});
		pair <long long,long long> now;
		for (it=trz[u]->begin(); it!=trz[u]->end(); it++)
		{
			now=dod(dodod, (*it));
			if (ten->find(now)!=ten->end())
				wyn[odl+1].first++;
			ten->insert(now);
		}
	}
	for (int i=1; i<(int)dzie.size(); i++)
	{
		int u=dzie[i];
		pair <long long, long long> dodod;
		dodod={mod1-wtu1[u], mod2-wtu2[u]};
		dodod=dod(dodod, {wtu1[x], wtu2[x]});
		pair <long long,long long> now;
		for (it=trz[u]->begin(); it!=trz[u]->end(); it++)
		{
			now=dod(dodod, (*it));
			ten->erase(ten->find(now));
			ten->insert((*it));
		}
	}
	wyn[odl+1].first++;
	trz[v]=ten;
	trz[v]->insert({sum1[v], sum2[v]});
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int p1, p2;
		char p3[2];
		scanf("%d%d%s", &p1, &p2, p3);
		graf[p1].push_back({p2, p3[0]});
		graf[p2].push_back({p1, p3[0]});
	}
	dfs1(1, 0, 0, 1, 1);
	debug() << range(wyn+1, wyn+1+n);
	for (int i=1; i<=w; i++)
	{
		wyn[i].first=n-wyn[i].first;
		wyn[i].second=i;
	}
	sort(wyn+1, wyn+1+w);
	printf("%d\n%d\n", wyn[1].first, wyn[1].second);
	return 0;
}
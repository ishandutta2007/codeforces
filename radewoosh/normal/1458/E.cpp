//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC target ("avx2")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;
const int inf=1007*1007*1007;

int n, m;

map<int,vi> mapa;

pii zap[nax];
int wyn[nax];

set<pii> setel;

void wrzuc(pii v)
{
	//~ debug() << "wstawiam " << v;
	if (v.first<=v.second)
		setel.insert(v);
}

void ciachnij(int v)
{
	auto it=setel.lower_bound({v, inf+1});
	if (it==setel.begin())
		return;
	it--;
	pii w=*it;
	if (w.first>v || w.second<v)
		return;
	setel.erase(it);
	wrzuc({w.first, v-1});
	wrzuc({v+1, w.second});
}

void skipnij(int v)
{
	while(v)
	{
		auto it=setel.begin();
		pii w=*it;
		if (w.second-w.first+1<=v)
		{
			v-=w.second-w.first+1;
			setel.erase(it);
		}
		else
		{
			setel.erase(it);
			wrzuc({w.first+v, w.second});
			v=0;
		}
	}
}

set<int> tmp;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		mapa[a].push_back(b);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		zap[i]={a, b};
		mapa[a].push_back(-i);
	}
	setel.insert({0, inf});
	
	int ost=-1;
	for (auto i : mapa)
	{
		skipnij(i.first-ost-1);
		ost=i.first;
		vi &wek=i.second;
		tmp.clear();
		int x=(*setel.begin()).first;
		//~ tmp.insert((*setel.begin()).first);
		//~ debug() << "sztu " << (*setel.begin()).first;
		for (int j : wek)
			if (j>=0)
				tmp.insert(j);
		int mini=x+1;
		for (int j : tmp)
			mini=min(mini, j);
		if (mini>x)
			tmp.insert(x);
		//~ debug() << i << " " << tmp << " " << setel;
		for (int j : wek)
		{
			if (j>=0)
				continue;
			int x=-j;
			if (tmp.count(zap[x].second))
				wyn[x]=0;
			else
				wyn[x]=1;
		}
		for (int j : tmp)
			ciachnij(j);
	}
	
	
	for (int i=1; i<=m; i++)
	{
		if (wyn[i])
			printf("WIN\n");
		else
			printf("LOSE\n");
	}
	return 0;
}
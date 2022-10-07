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
const ll inf=1e18;

int n, m;
vector<pair<int,ll>> graf[nax];

ll wyn;
ll odl[nax];
ll p1[nax];
ll p2[nax];

priority_queue<pll> kol;

void dij(ll sta)
{
	while(!kol.empty())
	{
		int v=kol.top().second;
		ll w=-kol.top().first;
		kol.pop();
		if (odl[v]!=-1)
			continue;
		odl[v]=w;
		for (auto i : graf[v])
			if (odl[i.first]==-1)
				kol.push({-(w+sta), i.first});
	}
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<=m; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		graf[a].push_back({b, c});
		graf[b].push_back({a, c});
	}
	for (int i=1; i<=n; i++)
		odl[i]=-1;
	kol.push({0, 1});
	dij(1);
	for (int i=1; i<=n; i++)
		p1[i]=odl[i];
	
	for (int i=1; i<=n; i++)
		odl[i]=-1;
	kol.push({0, n});
	dij(1);
	for (int i=1; i<=n; i++)
		p2[i]=odl[i];
	
	for (int i=1; i<=n; i++)
	{
		odl[i]=-1;
		kol.push({-(p1[i]+p2[i]), i});
	}
	dij(1);
	wyn=inf;
	for (int i=1; i<=n; i++)
	{
		for (auto j : graf[i])
		{
			wyn=min(wyn, j.second*(p1[i]+p2[j.first]+1));
			wyn=min(wyn, j.second*(odl[i]+2));
		}
	}
	printf("%lld\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
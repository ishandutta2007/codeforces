//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
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

int n, m, k;

vi graf[nax];

int dz[nax];
ll faj[nax];

map <int,ll> mapa[nax];

void dfs(int v)
{
	for (int i : graf[v])
	{
		dfs(i);
		if ((int)mapa[i].size()>(int)mapa[v].size())
			mapa[v].swap(mapa[i]);
		for (auto j : mapa[i])
			mapa[v][j.first]+=j.second;
	}
	if (!dz[v])
		return;
	ll jesz=faj[v];
	while(jesz)
	{
		auto it=mapa[v].upper_bound(dz[v]);
		if (it==mapa[v].end())
			break;
		if ((*it).second<=jesz)
		{
			jesz-=(*it).second;
			mapa[v].erase(it);
			continue;
		}
		(*it).second-=jesz;
		jesz=0;
	}
	mapa[v][dz[v]]+=faj[v];
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		graf[x].push_back(i);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dz[a]=b;
		faj[a]=c;
	}
	dfs(1);
	ll wyn=0;
	for (auto i : mapa[1])
		wyn+=i.second;
	printf("%lld\n", wyn);
	return 0;
}
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

int n;
vi graf[nax];

int wyn=1;

int dz[nax];
int zieldz[nax];
int zielnie[nax];
int bial[nax];

int save[nax];

int juz[nax];
int ma[nax];

void przep(int v, int u)
{
	juz[v]++;
	wyn=max(wyn, zieldz[v]+bial[u]+ma[v]-juz[v]);
	wyn=max(wyn, zielnie[v]+bial[u]+ma[v]-juz[v]);
	wyn=max(wyn, zieldz[u]+bial[v]);
	wyn=max(wyn, zielnie[u]+bial[v]);
	
	wyn=max(wyn, zieldz[v]+zieldz[u]+ma[v]-juz[v]);
	wyn=max(wyn, zielnie[v]+zieldz[u]+ma[v]-juz[v]);
	wyn=max(wyn, zieldz[v]+zielnie[u]+ma[v]-juz[v]);
	wyn=max(wyn, zielnie[v]+zielnie[u]+ma[v]-juz[v]);
	
	int stadz=zieldz[v];
	int stanie=zielnie[v];
	
	//~ zieldz[v]=max(zieldz[v], zieldz[v]+1);
	//~ zielnie[v]=max(zielnie[v], zielnie[v]+1);
	zieldz[v]=max(zieldz[v], zielnie[v]+zieldz[u]);
	zieldz[v]=max(zieldz[v], zielnie[v]+zielnie[u]);
	zieldz[v]=max(zieldz[v], zielnie[v]+bial[u]);
	bial[v]=max(bial[v], 1+zieldz[u]);
	bial[v]=max(bial[v], 1+zielnie[u]);
	zieldz[v]=max(zieldz[v], stadz+1);
	zielnie[v]=max(zielnie[v], stanie+1);
}

void dfs(int v, int oj)
{
	for (int i : graf[v])
		ma[v]++;
	bial[v]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		przep(v, i);
	}
	wyn=max(wyn, zieldz[v]);
	wyn=max(wyn, zielnie[v]);
	wyn=max(wyn, bial[v]);
	if (oj)
	{
		wyn=max(wyn, zieldz[v]+1);
		wyn=max(wyn, zielnie[v]+1);
	}
	//~ debug() << v << " " << zieldz[v] << " " << zielnie[v] << " " << bial[v];
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0);
	printf("%d\n", wyn);
	return 0;
}
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

int n, m;

vector<pair<int,ll>> drz[nax];
vector<pii> graf[nax];

pii sci[nax];
int xo[nax];

void edge(int a, int b, int x)
{
	graf[a].push_back({b, x});
	graf[b].push_back({a, x});
}

int bylo[nax];

int cykl;

void dfs1(int v, int k)
{
	//~ debug() << "kur " << v << " " << k;
	if (bylo[v])
	{
		if (bylo[v]!=k)
			cykl=1;
		return;
	}
	bylo[v]=k;
	for (pii i : graf[v])
		dfs1(i.first, k^(3*i.second));
}

void dfs2(int v, int oj)
{
	for (auto i : drz[v])
	{
		if (i.first==oj)
			continue;
		if (i.second>=0)
		{
			printf("%d %d %lld\n", v, i.first, i.second);
		}
		else
		{
			printf("%d %d %lld\n", v, i.first, (ll)(bylo[v]!=bylo[i.first]));
		}
		dfs2(i.first, v);
	}
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
	{
		drz[i].clear();
		graf[i].clear();
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		drz[a].push_back({b, c});
		drz[b].push_back({a, c});
		if (c>=0)
			edge(a, b, __builtin_popcountll(c)&1);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d%d", &a, &b, &xo[i]);
		sci[i]={a, b};
		edge(a, b, xo[i]);
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << graf[i];
	cykl=0;
	for (int i=1; i<=n; i++)
		bylo[i]=0;
	for (int i=1; i<=n; i++)
		if (!bylo[i])
			dfs1(i, 1);
	//~ debug() << range(bylo+1, bylo+1+n);
	if (cykl)
	{
		printf("NO\n");
		return;
	}
	printf("YES\n");
	dfs2(1, 0);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
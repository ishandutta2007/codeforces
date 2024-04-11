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
const int nax=3007;
const ll mod=1000*1000*1000+7;
const ll inf=1e18;

int n, m;

ll tab[nax];

vi graf[nax];

pll dp[nax][nax];
int roz[nax];

pll dod(pll a, pll b)
{
	return {a.first+b.first, a.second+b.second};
}

void przep(int v, int u)
{
	for (int i=0; i<roz[v]; i++)
		dp[0][i]=dp[v][i];
	for (int i=0; i<roz[v]+roz[u]; i++)
		dp[v][i]={-inf, 0};
	for (int i=0; i<roz[v]; i++)
		for (int j=0; j<=roz[u]; j++)
			dp[v][i+j]=max(dp[v][i+j], dod(dp[0][i], dp[u][j]));
}

void dfs1(int v, int oj)
{
	roz[v]=1;
	dp[v][0]={0, tab[v]};
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs1(i, v);
		przep(v, i);
		roz[v]+=roz[i];
	}
	dp[v][roz[v]]={-inf, 0};
	for (int i=roz[v]; i; i--)
		dp[v][i]=max(dp[v][i], {dp[v][i-1].first+(dp[v][i-1].second>0), 0});
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		tab[i]=x-tab[i];
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs1(1, 0);
	printf("%lld\n", dp[1][m-1].first+(dp[1][m-1].second>0));
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
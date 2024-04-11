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
const int nax=307*1007;
const ll mod=998244353;

int n;
vi graf[nax];

ll dp[nax][3];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void zrob(int v, int u)
{
	for (int i=0; i<3; i++)
	{
		dp[0][i]=dp[v][i];
		dp[v][i]=0;
	}
	//usuwam
	dod(dp[v][2], (dp[u][0]+dp[u][2])*dp[0][2]);
	dod(dp[v][1], (dp[u][0]+dp[u][2])*dp[0][1]);
	dod(dp[v][0], (dp[u][0]+dp[u][2])*dp[0][0]);
	
	
	//~ debug() << "po " << v << " " << u;
	//~ debug() << range(dp[v], dp[v]+3);
	//zostawiam
	dod(dp[v][1], dp[u][0]*(dp[0][1]+dp[0][2]));
	dod(dp[v][0], dp[u][0]*dp[0][0]);
	dod(dp[v][0], (dp[u][1]+dp[u][2])*(dp[0][1]+dp[0][2]));
	//~ debug() << "po " << v << " " << u;
	//~ debug() << range(dp[v], dp[v]+3);
}

void dfs(int v, int oj)
{
	dp[v][2]=1;
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		zrob(v, i);
	}
	//~ debug() << "kon " << v;
	//~ debug() << range(dp[v], dp[v]+3);
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
	printf("%lld\n", (dp[1][0]+dp[1][2])%mod);
	return 0;
}
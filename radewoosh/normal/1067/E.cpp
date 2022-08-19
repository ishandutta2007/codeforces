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
const int nax=500*1007;
const ll mod=998244353;

int n;
vi graf[nax];

pll dp[nax][2];
pll pom[2];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

void lacz(int v, int w)
{
	for (int i=0; i<2; i++)
	{
		pom[i]=dp[v][i];
		dp[v][i]=dp[0][0];
	}
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			for (int l=0; l<2; l++)
			{
				if (i || j || l)
				{
					dod(dp[v][i].first, pom[i].first*dp[w][j].first);
					dod(dp[v][i].second, pom[i].first*dp[w][j].second+dp[w][j].first*pom[i].second);
				}
				else
				{
					dod(dp[v][1].first, pom[i].first*dp[w][j].first);
					dod(dp[v][1].second, pom[i].first*dp[w][j].second+dp[w][j].first*pom[i].second+pom[i].first*dp[w][j].first*2);
				}
			}
		}
	}
}

void dfs(int v, int oj)
{
	dp[v][0]={1, 0};
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		lacz(v, i);
	}
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
	printf("%lld\n", (dp[1][0].second+dp[1][1].second)%mod);
	return 0;
}
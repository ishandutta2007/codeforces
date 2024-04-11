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

int n;

vi graf[nax];

vll war[nax];

vll dp[nax];

void dfs(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		ll a=dp[v][0]+max(abs(war[v][0]-war[i][0])+dp[i][0], abs(war[v][0]-war[i][1])+dp[i][1]);
		ll b=dp[v][1]+max(abs(war[v][1]-war[i][0])+dp[i][0], abs(war[v][1]-war[i][1])+dp[i][1]);
		dp[v]={a, b};
	}
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		war[i].clear();
		dp[i]={0, 0};
	}
	for (int i=1; i<=n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		war[i]={a, b};
	}
	for (int i=1; i<n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	dfs(1, 0);
	printf("%lld\n", max(dp[1][0], dp[1][1]));
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
		test();
	return 0;
}
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
const int nax=300*1007;
const int inf=1e9;

int n, m, k;

vector<pii> graf[nax];

int dp[13][nax];

int to_id(pii v)
{
	v.first--;
	v.second--;
	return v.first*m+v.second+1;
}

void edge(int a, int b, int c)
{
	graf[a].push_back({b, c});
	graf[b].push_back({a, c});
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (k&1)
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
				printf("-1 ");
			printf("\n");
		}
		return 0;
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<m; j++)
		{
			int x;
			scanf("%d", &x);
			edge(to_id({i, j}), to_id({i, j+1}), x);
		}
	}
	for (int i=1; i<n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			int x;
			scanf("%d", &x);
			edge(to_id({i, j}), to_id({i+1, j}), x);
		}
	}
	k>>=1;
	for (int h=1; h<=k; h++)
	{
		for (int i=1; i<=n*m; i++)
		{
			dp[h][i]=inf;
			for (pii l : graf[i])
				dp[h][i]=min(dp[h][i], dp[h-1][l.first]+l.second);
		}
	}
	for (int i=1; i<=n*m; i++)
	{
		printf("%d ", dp[k][i]*2);
		if (!(i%m))
			printf("\n");
	}
	return 0;
}
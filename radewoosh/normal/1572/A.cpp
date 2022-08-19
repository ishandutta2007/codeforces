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
vi farg[nax];

int bylo[nax];

vi post;

int dp[nax];
int kt[nax];

void dfs1(int v)
{
	bylo[v]=1;
	for (int i : graf[v])
		if (!bylo[i])
			dfs1(i);
	post.push_back(v);
	kt[v]=post.size();
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		farg[i].clear();
		bylo[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		int x, y;
		scanf("%d", &x);
		while(x--)
		{
			scanf("%d", &y);
			graf[y].push_back(i);
			farg[i].push_back(y);
		}
	}
	post.clear();
	for (int i=1; i<=n; i++)
	{
		if (bylo[i])
			continue;
		dfs1(i);
	}
	for (int i=1; i<=n; i++)
	{
		for (int j : graf[i])
		{
			if (kt[j]>kt[i])
			{
				printf("-1\n");
				return;
			}
		}
	}
	int wyn=0;
	for (int i : post)
	{
		dp[i]=1;
		for (int j : graf[i])
			dp[i]=max(dp[i], dp[j]+(j<i));
		wyn=max(wyn, dp[i]);
	}
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
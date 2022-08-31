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
const int nax=107;
const ll inf=1e18;

int n;
pair <ll,ll> tab[nax];

int czy[nax];
ll dp[nax][nax][nax];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

int check(ll v)
{
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			for (int l=0; l<=n; l++)
				dp[i][j][l]=inf;
	dp[0][0][0]=0;
	//~ debug() << v;
	for (int i=0; i<n; i++)
	{
		ll x=tab[i+1].first-v*tab[i+1].second;
		//~ debug() << imie(x);
		for (int j=0; j<=n; j++)
		{
			for (int l=0; l<=n; l++)
			{
				mini(dp[i+1][j+(l+1)*czy[i+1]][(l+1)*(1-czy[i+1])], dp[i][j][l]+x);
				if (j)
					mini(dp[i+1][j-1+l*czy[i+1]][l*(1-czy[i+1])], dp[i][j][l]);
			}
		}
	}
	//~ for (int i=0; i<=n; i++)
		//~ debug() << range(dp[n][i], dp[n][i]+1+n);
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			if (dp[n][i][j]<=0)
				return 1;
	return 0;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i].first);
		tab[i].first*=1000;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i].second);
	}
	sort(tab+1, tab+1+n);
	reverse(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
		czy[i]=(tab[i].first!=tab[i+1].first);
	ll bsa=1;
	ll bsb=1e13;
	ll bss;
	while(bsa<bsb)
	{
		bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%lld\n", bsa);
	return 0;
}
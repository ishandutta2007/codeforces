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

ll r1, r2, r3, d;

ll tab[nax];

ll kosz[nax][2];

ll dp[nax][2];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

int main()
{
	scanf("%d%lld%lld%lld%lld", &n, &r1, &r2, &r3, &d);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
	{
		kosz[i][0]=r1*tab[i]+r3;
		kosz[i][1]=min(r1*(tab[i]+2), r2+r1);
		kosz[i][1]=min(kosz[i][0], kosz[i][1]);
		//~ debug() << imie(i) << imie(range(kosz[i], kosz[i]+2));
	}
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			dp[i][j]=1e18;
	dp[1][1]=kosz[1][1];
	dp[1][0]=kosz[1][0];
	for (int i=1; i<n; i++)
	{
		mini(dp[i+1][0], dp[i][0]+kosz[i+1][0]);
		mini(dp[i+1][0], dp[i][1]+kosz[i+1][1]+2*d);
		mini(dp[i+1][1], dp[i][0]+kosz[i+1][1]);
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << dp[i][0] << " " << dp[i][1];
	ll suf=kosz[n][0];
	ll wyn=dp[n][0];
	for (int i=n; i>1; i--)
	{
		//~ debug() << i << " " << suf;
		wyn=min(wyn, suf+dp[i-1][0]);
		suf+=d+kosz[i-1][1];
	}
	wyn=min(wyn, dp[n-1][0]+kosz[n][1]+2*d);
	printf("%lld\n", wyn+d*(n-1));
	return 0;
}
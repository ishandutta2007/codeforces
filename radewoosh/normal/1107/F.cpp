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
const int nax=507;

int n;

ll a[nax];
ll b[nax];
ll k[nax];

int dos[nax];

ll dp[nax][nax];

ll wyn;

bool mniej(int x, int y)
{
	return b[x]>b[y];
}

void maxi(ll &a, ll b)
{
	a=max(a, b);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%lld", &a[i], &b[i], &k[i]);
		dos[i]=i;
	}
	sort(dos+1, dos+1+n, mniej);
	for (int h=1; h<=n; h++)
	{
		int i=dos[h];
		for (int j=0; j<=n; j++)
		{
			maxi(dp[h][j], dp[h-1][j]);
			maxi(dp[h][j], dp[h-1][j]+a[i]-b[i]*k[i]);
			maxi(dp[h][j+1], dp[h-1][j]+a[i]-b[i]*j);
			wyn=max(wyn, dp[h][j]);
		}
	}
	
	printf("%lld\n", wyn);
	return 0;
}
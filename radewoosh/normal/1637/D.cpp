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
const int nax=107;
const int vax=207*107;
using bn=bitset<vax>;
const ll inf=1e18;

int n;

ll a[nax];
ll b[nax];

ll baza;

ll dp[nax][vax];

void mini(ll &a, ll b)
{
	a=min(a, b);
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &a[i]);
	for (int i=1; i<=n; i++)
		scanf("%lld", &b[i]);
	baza=0;
	for (int i=1; i<=n; i++)
		baza+=a[i]*a[i]+b[i]*b[i];
	baza*=(n-1);
	debug() << imie(baza);
	for (int i=0; i<=n; i++)
		for (int j=0; j<vax; j++)
			dp[i][j]=inf;
	dp[0][0]=0;
	int s=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=0; j<=s; j++)
		{
			mini(dp[i][j+a[i]], dp[i-1][j]+j*a[i]+(s-j)*b[i]);
			mini(dp[i][j+b[i]], dp[i-1][j]+j*b[i]+(s-j)*a[i]);
		}
		s+=a[i]+b[i];
	}
	ll wyn=inf;
	for (int i=0; i<=s; i++)
		wyn=min(wyn, dp[n][i]);
	printf("%lld\n", baza+2*wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
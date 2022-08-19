//while (clock()<=69*CLOCKS_PER_SEC)
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

const int nax=5007;
using ll=long long;
const ll mod=1000*1000*1000+7;

int n, k;

ll tab[nax];

ll dp[nax][nax];

ll wyn;

ll pot(ll a, ll b)
{
	if (b<0)
		return 0;
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ret;
}

ll dziel(ll a, ll b)
{
	debug() << "z " << a << " " << b;
	return (pot(b, mod-2)*a)%mod;
}

inline void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	dp[0][0]=1;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<=i; j++)
		{
			dod(dp[i+1][j], dp[i][j]);
			dod(dp[i+1][j+1], dp[i][j]*tab[i+1]);
		}
	}
	debug() << "chuj";
	for (int i=1; i<=n; i++)
	{
		ll x=(dp[n][n-i])%mod;
		
		debug() << i << " " << x;
		ll y=1;
		for (int j=0; j<i; j++)
			y=(y*(k-j))%mod;
		y=(y*pot(n, k-i))%mod;
		
		if (!(i&1))
			y=(mod-y)%mod;
		
		debug() << i << " " << x << " " << y;
		
		dod(wyn, x*y);
	}
	debug() << "chuj";
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", dziel(wyn, pot(n, k)));
	return 0;
}
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

using ll=long long;
const int nax=5007;
const ll mod=1000*1000*1000+7;

ll n, k;

ll kom[nax][nax];

ll dp[nax];

ll wyn;

ll pot(ll a, ll b)
{
	a%=mod;
	ll ret=1;
	while(b)
	{
		if (b&1)
			ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

ll dziel(ll a, ll b)
{
	return (a*pot(b, mod-2))%mod;
}

int main()
{
	scanf("%lld%lld", &n, &k);
	for (int i=0; i<=k; i++)
	{
		kom[i][0]=1;
		for (int j=1; j<=i; j++)
			kom[i][j]=(kom[i-1][j]+kom[i-1][j-1])%mod;
	}
	dp[0]=0;
	for (int i=1; i<=k; i++)
	{
		ll niby=pot(i, k);
		for (int j=1; j<i; j++)
			niby=(niby-dp[j]*kom[i][j])%mod;
		
		niby%=mod;
		niby+=mod;
		niby%=mod;
		
		dp[i]=niby;
		
		//~ debug() << i << " " << dp[i];
	}
	ll li=1;
	ll mi=1;
	for (int i=1; i<=min(n, k); i++)
	{
		li=(li*(n+1-i))%mod;
		mi=(mi*i)%mod;
		
		ll ula=dziel(li, mi);
		
		//~ debug() << i << " " << li << " " << mi;
		
		ula=(ula*dp[i])%mod;
		
		wyn=(wyn+ula*pot(2, n-i))%mod;
	}
	
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}
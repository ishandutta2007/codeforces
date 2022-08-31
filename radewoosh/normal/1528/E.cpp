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
const ll mod=998244353;

int n;

ll dp[nax];
ll sum[nax];

ll inv[nax];

ll kom(ll v, ll ile)
{
	ll li=1;
	ll mi=1;
	for (int i=1; i<=ile; i++)
	{
		li=(li*(v-1+i))%mod;
		mi=(mi*inv[i])%mod;
	}
	return (li*mi)%mod;
}

ll mag[nax];

int main()
{
	inv[1]=1;
	for (int i=2; i<nax; i++)
		inv[i]=(inv[mod%i]*(mod-mod/i))%mod;
	scanf("%d", &n);
	dp[0]=1;
	sum[0]=1;
	for (int i=1; i<=n; i++)
	{
		ll tak=dp[i-1];
		ll nie=0;
		if (i>1)
			nie=sum[i-2];
		dp[i]=(kom(tak, 2)+tak*nie+tak)%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	ll wyn=0;
	ll tak=dp[n-1];
	ll nie=0;
	if (n-2>=0)
		nie=sum[n-2];
	//~ debug() << range(dp, dp+1+n);
	//~ debug() << tak << " " << nie;
	wyn=(kom(tak, 3)+kom(tak, 2)*nie%mod+tak*kom(nie, 2)%mod+kom(tak, 2)+tak*nie+tak)%mod;
	wyn%=mod;
	wyn*=2;
	wyn-=1;
	wyn+=mod;
	wyn%=mod;
	for (int i=1; i<=n; i++)
	{
		ll tak=dp[i-1];
		ll nie=0;
		if (i>1)
			nie=sum[i-2];
		mag[i]=(kom(tak, 2)+tak*nie)%mod;
	}
	{
		ll s=0;
		for (int i=n-1; i; i--)
		{
			wyn=(wyn+s*mag[i])%mod;
			s=(s+mag[n-i])%mod;
		}
	}
	printf("%lld\n", wyn);
	return 0;
}
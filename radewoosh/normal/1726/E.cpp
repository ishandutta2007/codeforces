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

ll inv(ll v)
{
	if (v<=1)
		return v;
	return inv(mod%v)*(mod-mod/v)%mod;
}

int n;

ll sil[nax];
ll odw[nax];

ll dp[nax];

ll kom(int a, int b)
{
	if (b>a || b<0)
		return 0;
	return sil[a]*odw[b]%mod*odw[a-b]%mod;
}

void test()
{
	scanf("%d", &n);
	dp[0]=1;
	dp[1]=1;
	for (int i=2; i<=n; i++)
	{
		dp[i]=(dp[i-1]+dp[i-2]*(i-1))%mod;
	}
	ll wyn=0;
	ll lo=1;
	for (int i=0; i<=n/2; i+=2)
	{
		int dwa=i;
		int jed=n-2*dwa;
		//~ debug() << imie(jed) << imie(dwa) << imie(lo) << dp[jed];
		ll kol=kom(jed+dwa, jed);
		
		wyn=(wyn+kol*lo%mod*dp[jed])%mod;
		lo=(lo*(i+1)*2)%mod;
	}
	printf("%lld\n", wyn);
}

int main()
{
	sil[0]=1;
	for (int i=1; i<nax; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[nax-1]=inv(sil[nax-1]);
	for (int i=nax-1; i; i--)
		odw[i-1]=(odw[i]*i)%mod;
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
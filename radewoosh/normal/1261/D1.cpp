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
const int nax=1000*1007;
const ll mod=998244353;

int n;
ll k;

ll tab[nax];

ll pot(ll a, ll b)
{
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

ll sil[nax];
ll odw[nax];
ll kom(ll a, ll b)
{
	return sil[a]*(odw[b]*odw[a-b]%mod)%mod;
}

int main()
{
	scanf("%d%lld", &n, &k);
	sil[0]=1;
	odw[0]=1;
	for (int i=1; i<=n; i++)
	{
		sil[i]=(sil[i-1]*i)%mod;
		odw[i]=dziel(1, sil[i]);
	}
	for (int i=0; i<n; i++)
		scanf("%lld", &tab[i]);
	ll wsz=pot(k, n);
	ll tak=1;
	int inne=0;
	ll opc=0;
	for (int i=0; i<n; i++)
	{
		if (tab[i]==tab[(i+1)%n])
			tak=(tak*k)%mod;
		else
			inne++;
	}
	for (int j=0; j<=inne; j+=2)
	{
		ll ter=kom(inne, j)*kom(j, j/2)%mod;
		ter*=pot(k-2, inne-j);
		ter%=mod;
		opc=(opc+ter)%mod;
	}
	ll wyn=(wsz-tak*opc);
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", dziel(wyn, 2));
	return 0;
}
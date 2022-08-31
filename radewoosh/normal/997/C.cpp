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
using pii=pair <int,int>;
const int nax=1000*1007;
const ll mod=998244353;

void fix(ll &v)
{
	v%=mod;
	v+=mod;
	v%=mod;
}

void ans(ll v)
{
	fix(v);
	printf("%lld\n", v);
	exit(0);
}

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

int n;

ll sil[nax];
ll odw[nax];

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

ll komb(int a, int b)
{
	if (b<0 || b>a)
		return 0;
	return (((odw[a-b]*odw[b])%mod)*sil[a])%mod;
}

int main()
{
	scanf("%d", &n);
	sil[0]=1;
	for (int i=1; i<=n; i++)
		sil[i]=(sil[i-1]*i)%mod;
	odw[n]=pot(sil[n], mod-2);
	for (int i=n-1; i>=0; i--)
		odw[i]=(odw[i+1]*(i+1))%mod;
	for (int i=1; i<=n; i++)
		dod(wyn, (komb(n, i)*pot(pot(3, n)-3, n-i)%mod)*pot(3, i));
	ll znak=1;
	for (int i=1; i<=n; i++)
	{
		ll wyb=komb(n, i);
		ll kol=pot(3, i);
		ll roz=kol-3;
		dod(wyn, znak*(wyb*roz%mod)*pot(3, (ll)n*(n-i)));
		
		dod(wyn, znak*wyb*3*pot(pot(3, n-i)-1, n));
		
		
		znak*=-1;
	}
	ans(wyn);
	return 0;
}
//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
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
const int nax=1000*1007;
const ll mod=1000*1000*1000+9;
const ll inv=(mod+1)/2;

int n, k;
ll a, b;

char wcz[nax];

ll tab[nax];

ll wyn;

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

ll geo(ll a, ll b, ll ile)
{
	if (b==1)
		return (a*ile)%mod;
	return (a*dziel(pot(b, ile)-1, b-1))%mod;
}

int main()
{
	scanf("%d%lld%lld%d", &n, &a, &b, &k);
	scanf("%s", wcz);
	for (int i=0; i<k; i++)
	{
		if (wcz[i]=='+')
			tab[i]=1;
		else
			tab[i]=-1;
	}
	int m=(n+1)/k;
	
	for (int i=0; i<k; i++)
	{
		ll x=tab[i]*((pot(b, i)*pot(a, n-i))%mod);
		x%=mod;
		wyn=(wyn+geo(x, dziel(pot(b, k), pot(a, k)), m))%mod;
	}
	
	//~ wyn%=mod;
	//~ if ((n+1)&1)
		//~ wyn+=;
	//~ wyn=(wyn*inv)%mod;
	
	wyn%=mod;
	wyn+=mod;
	wyn%=mod;
	printf("%lld\n", wyn);
	return 0;
}
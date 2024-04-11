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
const ll inf=1e18;

int n;
ll a, r, m;

ll tab[nax];
ll pref[nax];

ll wyn=inf;

ll licz(int v, ll g)
{
	if (g<tab[v] || g>tab[v+1])	
		return inf;
	ll brak=v*g-pref[v];
	ll nad=pref[n]-pref[v]-(n-v)*g;
	ll ret=0;
	if (brak>nad)
		ret+=(brak-nad)*a+nad*m;
	else
		ret+=(nad-brak)*r+brak*m;
	return ret;
}

void szuk(ll v)
{
	int g=1;
	while(g<n-1 && tab[g+1]<=v)
		g++;
	licz(g, v);
}

int main()
{
	scanf("%d%lld%lld%lld", &n, &a, &r, &m);
	if (n==1)
		wyn=0;
	m=min(m, a+r);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
		pref[i]=pref[i-1]+tab[i];
	szuk(pref[n]/n);
	szuk((pref[n]+n-1)/n);
	for (int i=1; i<n; i++)
	{
		ll tsa=tab[i];
		ll tsb=tab[i+1];
		while(tsa<tsb)
		{
			ll ts1=(tsa+tsb)>>1;
			ll ts2=ts1+1;
			if (licz(i, ts1)<licz(i, ts2))
				tsb=ts1;
			else
				tsa=ts2;
		}
		wyn=min(wyn, licz(i, tsa));
		wyn=min(wyn, licz(i, tab[i]));
		wyn=min(wyn, licz(i, tab[i+1]));
	}
	printf("%lld\n", wyn);
	return 0;
}
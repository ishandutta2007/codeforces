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
const int inf=1007*1007;

int n;

ll tab[nax];

void duzo()
{
	printf("INF\n");
}

ll kosz(int a, int b, ll v)
{
	return tab[a]*tab[b]+v*(tab[a]+tab[b]);
}

ll f(ll v)
{
	ll ret=kosz(1, n, v);
	for (int i=2; i<n; i++)
		ret+=min(kosz(1, i, v), kosz(n, i, v));
	return ret;
}

void test()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	ll dol=0;
	ll gora=0;
	for (int i=2; i<=n; i++)
		dol+=tab[1]+tab[i];
	for (int i=1; i<n; i++)
		gora+=tab[n]+tab[i];
	if (gora<0 || dol>0)
	{
		duzo();
		return;
	}
	ll tsa=-inf;
	ll tsb=inf;
	while(tsa<tsb)
	{
		ll ts1=(tsa+inf+tsb+inf)/2-inf;
		ll ts2=ts1+1;
		if (f(ts1)<f(ts2))
			tsa=ts2;
		else
			tsb=ts1;
	}
	printf("%lld\n", f(tsa));
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
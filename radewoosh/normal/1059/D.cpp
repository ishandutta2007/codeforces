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
using ld=long double;
const ld inf=1e18;

int n;
pll tab[nax];

int check(ld r)
{
	ld pra=inf;
	ld lew=-inf;
	for (int i=1; i<=n; i++)
	{
		ld odl=abs((ld)tab[i].second-r);
		ld bok=sqrt(r*r-odl*odl);
		lew=max(lew, tab[i].first-bok);
		pra=min(pra, tab[i].first+bok);
	}
	return (lew<=pra);
}

int main()
{
	scanf("%d", &n);
	set <ll> setel;
	ll naj=0;
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
		setel.insert(tab[i].second/abs(tab[i].second));
		tab[i].second=abs(tab[i].second);
		naj=max(naj, tab[i].second);
	}
	if ((int)setel.size()==2)
	{
		printf("-1\n");
		return 0;
	}
	ld bsa=naj/2.0;
	ld bsb=inf;
	ld bss;
	for (int h=0; h<150; h++)
	{
		bss=(bsa+bsb)/2;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss;
	}
	printf("%.9lf\n", (double)bsa);
	return 0;
}
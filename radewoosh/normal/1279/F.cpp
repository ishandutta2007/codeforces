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

int n, k, d;

char wcz[nax];
int tab[nax];

int wyn=nax;

pll dp[nax];

pll daj(ll v)
{
	for (int i=1; i<=n; i++)
	{
		int x=max(i-d, 0);
		pll raz, dwa;
		
		raz=dp[i-1];
		raz.first+=tab[i];
		
		dwa=dp[x];
		dwa.first+=v;
		dwa.second++;
		
		dp[i]=min(raz, dwa);
	}
	return dp[n];
}

int licz()
{
	ll bsa=-1e9;
	ll bsb=1e9;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb)>>1;
		pll wez=daj(bss);
		if (wez.second<=k)
			bsb=bss;
		else
			bsa=bss+1;
	}
	pll wez=daj(bsa);
	return wez.first-k*bsa;
}

int main()
{
	scanf("%d%d%d", &n, &k, &d);
	if (k*(ll)d>=n)
	{
		printf("0\n");
		return 0;
	}
	scanf("%s", wcz+1);
	for (int i=1; i<=n; i++)
		if (wcz[i]>='a' && wcz[i]<='z')
			tab[i]=1;
	wyn=min(wyn, licz());
	for (int i=1; i<=n; i++)
		tab[i]^=1;
	wyn=min(wyn, licz());
	printf("%d\n", wyn);
	return 0;
}
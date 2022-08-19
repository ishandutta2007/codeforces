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
using duz=long long;

int n;
ll k;

ll tab[nax];

ll rob[nax];

ll wzrost(int v, ll x)
{
	return tab[v]-3*(x-1)*x-1;
}

ll licz(ll v)
{
	ll ret=0;
	for (int i=1; i<=n; i++)
	{
		ll bsa=0;
		ll bsb=tab[i];
		while(bsa<bsb)
		{
			ll bss=(bsa+bsb+2)>>1;
			if (wzrost(i, bss)>=v)
				bsa=bss;
			else
				bsb=bss-1;
		}
		rob[i]=bsa;
		ret+=bsa;
	}
	//~ debug() << v << " " << ret;
	return ret;
}

int main()
{
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	ll bsb=1e10;
	ll bsa=-4e18;
	while(bsa<bsb)
	{
		ll bss=(bsa+bsb+2)>>1;
		if (licz(bss)>=k)
			bsa=bss;
		else
			bsb=bss-1;
	}
	licz(bsa);
	ll jest=k;
	for (int i=1; i<=n; i++)
		jest-=rob[i];
	for (int i=1; i<=n; i++)
	{
		if (rob[i] && jest<0 && wzrost(i, rob[i])==bsa)
		{
			jest++;
			rob[i]--;
		}
		printf("%lld ", rob[i]);
	}
	printf("\n");
	return 0;
}
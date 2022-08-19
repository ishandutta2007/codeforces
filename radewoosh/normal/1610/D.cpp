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
const ll mod=1000*1000*1000+7;
const int d=30;

int n;

ll tab[nax];

ll dp[nax][2][2];

ll ile[nax];

void dod(ll &a, ll b)
{
	a=(a+b)%mod;
}

ll pot[nax];

int main()
{
	pot[0]=1;
	for (int i=1; i<nax; i++)
		pot[i]=(pot[i-1]*2)%mod;
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		ll x=0;
		while(!(tab[i]%(1LL<<(x+1))))
			x++;
		tab[i]=x;
		ile[x]++;
		//~ debug() << x;
	}
	ll wyn=0;
	for (int i=1; i<d; i++)
	{
		if (!ile[i])
			continue;
		ll opc=pot[ile[i]-1]-1;
		for (int j=i+1; j<d; j++)
			opc=(opc*pot[ile[j]])%mod;
		opc=(opc+mod)%mod;
		opc=(opc+mod)%mod;
		wyn=(wyn+opc)%mod;
	}
	ll mno=pot[ile[0]]-1;
	for (int i=1; i<d; i++)
		mno=(mno*pot[ile[i]])%mod;
	dod(wyn, mno);
	printf("%lld\n", wyn);
	return 0;
}
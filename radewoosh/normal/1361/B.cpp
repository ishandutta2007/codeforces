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
const ll inf=1000LL*1000LL*1000LL*1000LL*2;
const int d=43;
using ld=long double;

int n, p;

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

ll biepot[nax];

void test()
{
	scanf("%d%d", &n, &p);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	biepot[0]=1;
	for (int i=1; i<=d; i++)
		biepot[i]=min(biepot[i-1]*p, inf);
		
	sort(tab+1, tab+1+n);
	ll rmod=0;
	ll rzecz=0;
	tab[n+1]=inf;
	for (int h=n; h; h--)
	{
		if (rzecz>=0)
		{
			rmod=(rmod-1+mod)%mod;
			rzecz-=1;
		}
		else
		{
			rmod=(rmod+1+mod)%mod;
			rzecz+=1;
		}
		//~ debug() << h << " " << rmod << " " << rzecz;
		ll brak=tab[h]-tab[h-1];
		ll wez=biepot[min((ll)d, brak)];
		if (wez*(ld)rzecz>inf)
		{
			rzecz=inf;
		}
		else
		{
			if (wez*(ld)rzecz<-inf)
			{
				rzecz=-inf;
			}
			else
			{
				rzecz=wez*rzecz;
				rzecz=min(rzecz, inf);
				rzecz=max(rzecz, -inf);
			}
		}
		rmod=(rmod*pot(p, tab[h]-tab[h-1]))%mod;
		//~ debug() << h << " " << rmod << " " << rzecz;
	}
	if (rzecz<0)
		rmod=(mod-rmod)%mod;
	printf("%lld\n", rmod);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
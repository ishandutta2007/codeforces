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
const int nax=1200*1007;
const ll mod1=998244353;
const ll mod2=1000*1000*1000+7;

ll n;

ll wyn;

ll ztylu;

ll spoko(ll v)
{
	int ret=0;
	while(v)
	{
		if ((v%10)!=1)
			return 0;
		v/=10;
		ret++;
	}
	return ret;
}

ll meczuje(ll v)
{
	ll ret=0;
	ll dod=1;
	while(v<=n)
	{
		ret+=min(dod, n+1-v);
		v*=10;
		dod*=10;
	}
	return ret;
}

int speedup;

ll pot[nax];

ll sumpre(ll v)
{
	v%=mod2;
	return (v*(v-1)/2)%mod2;
}

void rek(ll v)
{
	ll mecz=meczuje(v);
	if (!mecz)
		return;
	if (mecz==1 || !spoko(mecz))
	{
		ztylu++;
		{
			ll w=ztylu-v;
			w%=mod1;
			w+=mod1;
			w%=mod1;
			wyn=(wyn+w)%mod2;
		}
		for (int i=0; i<10; i++)
			rek(v*10+i);
		return;
	}
	int d=spoko(mecz);
	ll x=v;
	ll dlu=1;
	int ok=1;
	ll pier=ztylu+1;
	for (int i=0; i<d; i++, x*=10, dlu*=10)
	{
		ll war=(pier-x+mod1*mod1)%mod1;
		if (war+mecz-1>=mod1 || war-(mecz-1)<0)
		{
			ok=0;
			break;
		}
	}
	if (!ok)
	{
		ztylu++;
		{
			ll w=ztylu-v;
			w%=mod1;
			w+=mod1;
			w%=mod1;
			wyn=(wyn+w)%mod2;
		}
		for (int i=0; i<10; i++)
			rek(v*10+i);
		return;
	}
	//~ debug() << mecz << " " << d;
	x=v;
	dlu=1;
	for (int i=0; i<d; i++, x*=10, dlu*=10)
	{
		ll war=(pier-x+mod1*mod1)%mod1;
		wyn=(wyn+war*pot[i]%mod2-sumpre(dlu))%mod2;
	}
	wyn=(wyn+sumpre(mecz))%mod2;
	speedup++;
	ztylu+=mecz;
}

int main()
{
	pot[0]=1;
	for (int i=1; i<=12; i++)
		pot[i]=pot[i-1]*10;
	scanf("%lld", &n);
	for (int i=1; i<10; i++)
		rek(i);
	assert(ztylu==n);
	wyn%=mod2;
	wyn+=mod2;
	wyn%=mod2;
	printf("%lld\n", wyn);
	debug() << imie(speedup);
	return 0;
}
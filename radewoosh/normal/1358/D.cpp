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
ll d;
ll tab[nax];

ll pref[nax];
ll spref[nax];

ll wyn;

ll ary(ll a, ll b)
{
	return (a+b)*(b-a+1)/2;
}

void ogar(int a, int b)
{
	debug() << a << " " << b;
	assert(a!=b);
	ll pomie=spref[b-1]-spref[a];
	int resz=d-(pref[b-1]-pref[a]);
	int lew=tab[a];
	int pra=tab[b];
	int tsa=0;
	int tsb=pra;
	tsa=max(tsa, resz-lew);
	assert(tsa<=tsb);
	debug() << a << " " << b << imie(lew) << imie(pra) << imie(resz) << imie(tsa) << imie(tsb);
	while(tsa<tsb)
	{
		int ts1=(tsa+tsb)>>1;
		int ts2=ts1+1;
		ll x=ary(lew-(resz-ts1)+1, lew)+ary(1, ts1);
		ll y=ary(lew-(resz-ts2)+1, lew)+ary(1, ts2);
		if (x>y)
			tsb=ts1;
		else
			tsa=ts2;
	}
	wyn=max(wyn, pomie+ary(lew-(resz-tsa)+1, lew)+ary(1, tsa));
}

int main()
{
	scanf("%d%lld", &n, &d);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=n; i++)
		tab[n+i]=tab[n+n+i]=tab[i];
	for (int i=1; i<=3*n; i++)
	{
		pref[i]=pref[i-1]+tab[i];
		spref[i]=spref[i-1]+ary(1, tab[i]);
	}
	int w=1;
	for (int i=1; i<=n; i++)
	{
		w=max(w, i);
		while(pref[w]-pref[i-1]<d)
			w++;
		if (tab[i]>=d)
			wyn=max(wyn, ary(tab[i]-d+1, tab[i]));
		else
			for (int j=w; pref[j]-pref[i]<d; j++)
				ogar(i, j);
	}
	
	printf("%lld\n", wyn);
	return 0;
}
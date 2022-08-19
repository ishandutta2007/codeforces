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
const ll inf=2e9;

int n;
pll tab[nax];

struct myset
{
	multiset<ll> setel;
	ll off=0;
	void dowsz(ll v)
	{
		off+=v;
	}
	ll pier()
	{
		auto it=setel.begin();
		return (*it)+off;
	}
	int roz()
	{
		return setel.size();
	}
	ll ost()
	{
		auto it=setel.end();
		it--;
		return (*it)+off;
	}
	void wloz(ll v)
	{
		setel.insert(v-off);
	}
	void wyjmij(ll v)
	{
		auto it=setel.find(v-off);
		setel.erase(it);
	}
	void wypisz()
	{
		debug() << wartosci();
	}
	vll wartosci()
	{
		vll ret;
		for (ll i : setel)
			ret.push_back(i+off);
		return ret;
	}
};

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
		tab[i].first+=tab[i].second;
	}
	sort(tab+1, tab+1+n);
	//~ debug() << range(tab+1, tab+1+n);
	myset dol, gor;
	ll winf=0;
	int juz=0;
	for (int i=n; i; i--)
	{
		ll y=tab[i].second;
		ll x=tab[i].first;
		winf+=inf-y;
		juz++;
		gor.wloz(y);
		gor.wloz(y);
		while(dol.roz()<juz)
		{
			ll wez=gor.pier();
			gor.wyjmij(wez);
			dol.wloz(wez);
		}
		while(dol.ost()>gor.pier())
		{
			ll a=dol.ost();
			ll b=gor.pier();
			dol.wyjmij(a);
			gor.wyjmij(b);
			dol.wloz(b);
			gor.wloz(a);
		}
		//~ debug() << tab[i];
		//~ dol.wypisz();
		//~ gor.wypisz();
		//~ debug() << imie(winf);
		dol.dowsz(-(x-tab[i-1].first));
	}
	ll wyn=winf-inf*n;
	for (ll i : dol.wartosci())
		if (i>=0)
			wyn+=i;
	for (ll i : gor.wartosci())
		if (i>=0)
			wyn+=i;
	
	
	printf("%lld\n", wyn);
	return 0;
}
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

void ff()
{
	fflush(stdout);
}

ll ukr;

ll pyt(ll v)
{
	printf("? %lld\n", v);
	ff();
	//~ return __gcd(v, ukr);
	ll x;
	scanf("%lld", &x);
	return x;
}

ll ans(ll v)
{
	printf("! %lld\n", v);
	ff();
}

int czypie(ll v)
{
	for (ll i=2; i*i<=v; i++)
		if (!(v%i))
			return 0;
	return 1;
}

vll pie;

vll fac(ll v)
{
	vll ret;
	for (ll i : pie)
	{
		while(!(v%i))
		{
			v/=i;
			ret.push_back(i);
		}
	}
	return ret;
}

void test()
{
	//~ scanf("%lld", &ukr);
	vector<vll> podz;
	ll ost=inf;
	vll kop=pie;
	while(!kop.empty())
	{
		if (ost>inf/kop[0])
		{
			podz.push_back(vll{});
			ost=1;
		}
		int w=0;
		while(w+1<(int)kop.size() && kop[w+1]<=inf/ost)
			w++;
		ll x=kop[w];
		podz.back().push_back(x);
		kop.erase(kop.begin()+w);
		ost*=x;
	}
	debug() << imie(podz.size());
	vll dz;
	for (vll i : podz)
	{
		ll ter=1;
		for (ll j : i)
			ter*=j;
		vll wez=fac(pyt(ter));
		//~ debug() << wez;
		for (ll j : wez)
			dz.push_back(j);
	}
	if (dz.empty())
	{
		ans(8);
		return;
	}
	ll znam=1;
	ll nowe=1;
	for (ll i : dz)
		nowe*=i;
	for (int h=1; h<=4 && nowe>1; h++)
	{
		ll ter=nowe;
		//~ debug() << imie(ter) << imie(znam);
		ll p=znam;
		while(p<=inf/ter)
			p*=ter;
		ll sta=znam;
		znam=pyt(p);
		nowe=znam/sta;
	}
	ll ma=0;
	for (ll i=1; i*i<=znam; i++)
	{
		if (!(znam%i))
		{
			ma++;
			if (znam/i!=i)
				ma++;
		}
	}
	ans(max(ma*2, ma+7));
}

int main()
{
	for (ll i=2; i<=770; i++)
		if (czypie(i))
			pie.push_back(i);
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
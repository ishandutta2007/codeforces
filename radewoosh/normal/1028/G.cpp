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
const int nax=250*1007;
const ll naj=10004205361450474LL;
const int d=5;
const ll k=10*1000;

void ff()
{
	fflush(stdout);
}

int over(ll a, ll b)
{
	if (!a || !b)
		return 0;
	ll r=a*b;
	if ((r/a)!=b || (r/b)!=a)
		return 0;
	return 1;
}

ll moge(ll s, int jesz, ll lim)
{
	if (lim==k)
		lim=min(lim, s);
	if (s>naj)
		return s;
	if (lim<0)
		return s-2;
	if (jesz==1)
		return s+min(s, lim)-1;
	if (s>=k && lim==k)
	{
		ll ret=0;
		for (int i=1; i<=jesz; i++)
			ret=k+ret*(k+1);
		return s+ret-1;
	}
	//~ ll bsa=s+1;
	//~ ll bsb=naj+1;
	//~ ll bss;
	//~ while(bsa<bsb)
	//~ {
		//~ bss=(bsa+bsb+2)/2;
		
	//~ }
	ll w=moge(s, jesz-1, min(s, k));
	//~ debug() << "gor " << jesz << "  " << w;
	return moge(w+2, jesz, lim-1);
	//~ ll wez=moge();
}

pll pyt(vll wek)
{
	sort(wek.begin(), wek.end());
	vll pom;
	for (ll i : wek)
		if (pom.empty() || i!=pom.back())
			pom.push_back(i);
	wek=pom;
	printf("%d", (int)wek.size());
	for (ll i : wek)
		printf(" %lld", i);
	printf("\n");
	ff();
	int x;
	scanf("%d", &x);
	//~ x=wek.size();
	if (x==-1)
		exit(0);
	if (x==-2)
		assert(0);
	ll lew=-naj;
	ll pra=2*naj;
	if (x>0)
		lew=max(lew, wek[x-1]+1);
	if (x<(int)wek.size())
		pra=min(pra, wek[x]-1);
	return {lew, pra};
}

void szuk(ll pocz, ll kon, int jesz)
{
	ll ter=min(k, pocz);
	if (kon-pocz+1<=ter)
	{
		vll daj;
		for (ll i=pocz; i<=kon; i++)
			daj.push_back(i);
		pyt(daj);
		assert(0);
	}
	ll ost=pocz-1;
	vll daj;
	while(ost<kon)
	{
		ll w=moge(ost+1, jesz-1, k);
		w=min(w, kon);
		if (w==kon)
			break;
		daj.push_back(w+1);
		ost=w+1;
	}
	pll r=pyt(daj);
	r.first=max(r.first, pocz);
	r.second=min(r.second, kon);
	szuk(r.first, r.second, jesz-1);
}

int main()
{
	assert(moge(1, d, 1)>=naj);
	szuk(1, naj, d);
	return 0;
}
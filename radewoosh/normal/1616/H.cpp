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
const ll mod=998244353;

int n;
ll k;
ll tab[nax];

ll pot[nax];

ll kom(int a, int b)
{
	return (pot[a]-1)*(pot[b]-1)%mod;
}

ll rek2(vll a, vll b, int gl, ll lim)
{
	if (a.empty() || b.empty() || gl==-1)
	{
		return pot[a.size()+b.size()]-1;
		//~ return (pot[a.size()]-1)*(pot[b.size()]-1)%mod;
	}
	if ((1LL<<gl)>lim)
	{
		vll a1, a2, b1, b2;
		ll gra=(1LL<<gl);
		for (ll i : a)
		{
			if (i<gra)
				a1.push_back(i);
			else
				a2.push_back(i-gra);
		}
		for (ll i : b)
		{
			if (i<gra)
				b1.push_back(i);
			else
				b2.push_back(i-gra);
		}
		ll wez=(rek2(a1, b1, gl-1, lim)+rek2(a2, b2, gl-1, lim)+kom(a1.size(), a2.size())+kom(b1.size(), b2.size()))%mod;
		//~ debug() << a << " " << b << " " << gl << " " << lim << " a " << wez;
		return wez;
	}
	vll a1, a2, b1, b2;
	ll gra=(1LL<<gl);
	for (ll i : a)
	{
		if (i<gra)
			a1.push_back(i);
		else
			a2.push_back(i-gra);
	}
	for (ll i : b)
	{
		if (i<gra)
			b1.push_back(i);
		else
			b2.push_back(i-gra);
	}
	ll wez=((rek2(a1, b2, gl-1, lim-gra)+1)*(rek2(a2, b1, gl-1, lim-gra)+1)-1)%mod;
	//~ debug() << a << " " << b << " " << gl << " " << lim << " b " << wez;
	return wez;
}

ll rek(vll wek, int gl)
{
	if (gl==-1 || wek.empty())
	{
		return pot[wek.size()]-1;
	}
	if ((1LL<<gl)>k)
	{
		vll raz, dwa;
		ll gra=(1LL<<gl);
		for (ll i : wek)
		{
			if (i<gra)
				raz.push_back(i);
			else
				dwa.push_back(i-gra);
		}
		ll wez=(rek(raz, gl-1)+rek(dwa, gl-1))%mod;
		//~ debug() << wek << " " << gl << " a " << wez;
		return wez;
	}
	vll raz, dwa;
	ll gra=(1LL<<gl);
	for (ll i : wek)
	{
		if (i<gra)
			raz.push_back(i);
		else
			dwa.push_back(i-gra);
	}
	ll wez=rek2(raz, dwa, gl-1, k-gra);
	//~ debug() << wek << " " << gl << " b " << wez;
	return wez;
}

int main()
{
	pot[0]=1;
	for (int i=1; i<nax; i++)
		pot[i]=pot[i-1]*2%mod;
	scanf("%d%lld", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	sort(tab+1, tab+1+n);
	vll wek;
	for (int i=1; i<=n; i++)
		wek.push_back(tab[i]);
	ll wez=rek(wek, 29);
	wez%=mod;
	wez+=mod;
	wez%=mod;
	printf("%lld\n", wez);
	return 0;
}
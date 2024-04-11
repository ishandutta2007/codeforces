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
const int nax=1007*1007;
const int n1=(1<<18);
const ll mod=998244353;

int n;
ll tab[nax];
int q;

ll o100;

ll dziel(ll a, ll b)
{
	ll wyk=mod-2;
	while(wyk)
	{
		if (wyk&1)
			a=(a*b)%mod;
		b=(b*b)%mod;
		wyk>>=1;
	}
	return a;
}

struct f
{
	ll sta=0;
	ll nast=1;
	ll x=0;
	void fix()
	{
		sta%=mod;
		nast%=mod;
		x%=mod;
	}
	ll eval()
	{
		ll li=sta;
		ll mi=(mod+1-x)%mod;
		return dziel(li, mi);
	}
};

f operator *(f a, f b)
{
	f ret;
	ret.sta=(a.sta+b.sta*a.nast)%mod;
	ret.x=(a.x+b.x*a.nast)%mod;
	ret.nast=(a.nast*b.nast)%mod;
	return ret;
}

f fake=f();

f drz[nax];
set <int> setel;

ll wyn;

int czek[nax];

f czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drz[v];
	}
	if (a>grab || b<graa)
	{
		return fake;
	}
	return czyt((v<<1), a, (a+b)>>1, graa, grab)*czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
}

int main()
{
	scanf("%d%d", &n, &q);
	o100=dziel(1, 100);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]=(tab[i]*o100)%mod;
	}
	
	
	for (int i=1; i<=n; i++)
	{
		f ter;
		ter.sta=1;
		ter.nast=tab[i];
		ter.x=mod+1-tab[i];
		drz[n1-1+i]=ter;
	}
	for (int i=n1-1; i; i--)
		drz[i]=drz[2*i]*drz[2*i+1];
	setel.insert(1);
	setel.insert(n+1);
	wyn=czyt(1, 1, n1, 1, n).eval();
	debug() << imie(wyn);
	while(q--)
	{
		int v;
		scanf("%d", &v);
		if (!czek[v])
		{
			auto it=setel.lower_bound(v);
			int p=(*it);
			it--;
			int l=(*it);
			wyn-=czyt(1, 1, n1, l, p-1).eval();
			wyn+=czyt(1, 1, n1, l, v-1).eval();
			wyn+=czyt(1, 1, n1, v, p-1).eval();
			setel.insert(v);
		}
		else
		{
			setel.erase(v);
			auto it=setel.lower_bound(v);
			int p=(*it);
			it--;
			int l=(*it);
			wyn+=czyt(1, 1, n1, l, p-1).eval();
			wyn-=czyt(1, 1, n1, l, v-1).eval();
			wyn-=czyt(1, 1, n1, v, p-1).eval();
		}
		wyn%=mod;
		wyn+=mod;
		wyn%=mod;
		printf("%lld\n", wyn);
		czek[v]^=1;
	}
	return 0;
}
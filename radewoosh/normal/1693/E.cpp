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
const int n1=(1<<18);

int n;
int tab[nax];

struct info
{
	vector<pii> wyj;//first to stan, second to dodanie
};

info operator +(const info &a, const info &b)
{
	info ret;
	ret.wyj.resize(3);
	for (int i=0; i<3; i++)
	{
		int x=a.wyj[i].first;
		ret.wyj[i]={b.wyj[x].first, b.wyj[x].second+a.wyj[i].second};
	}
	return ret;
}

info drz[nax];

//0 to JEDYNKI
int polew[nax];
int popra[nax];

ll wyn;

info daj(int l, int p)
{
	info ret;
	ret.wyj.resize(3);
	if (l && p)
	{
		for (int i=0; i<3; i++)
			ret.wyj[i]={0, 1};
		return ret;
	}
	if (!l && !p)
	{
		for (int i=0; i<3; i++)
			ret.wyj[i]={i, 0};
		return ret;
	}
	if (l)
	{
		ret.wyj[0]={1, 0};
		ret.wyj[1]={1, 0};
		ret.wyj[2]={0, 1};
		return ret;
	}
	if (p)
	{
		ret.wyj[0]={2, 0};
		ret.wyj[1]={0, 1};
		ret.wyj[2]={2, 0};
		return ret;
	}
	assert(0);
}

void upd(int v)
{
	if (!v)
		return;
	drz[n1-1+v]=daj(polew[v], popra[v]);
	v+=n1-1;
	v>>=1;
	while(v)
	{
		drz[v]=(drz[2*v+1]+drz[2*v]);
		v>>=1;
	}
}

info glo;

void czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		glo=(glo+drz[v]);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab);
	czyt((v<<1), a, (a+b)>>1, graa, grab);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		popra[tab[i]]++;
	for (int i=1; i<2*n1; i++)
		drz[i]=daj(0, 0);
	for (int i=1; i<=n; i++)
		drz[n1-1+i]=daj(0, popra[i]);
	for (int i=n1-1; i; i--)
		drz[i]=(drz[2*i+1]+drz[2*i]);
	for (int i=1; i<=n; i++)
	{
		popra[tab[i]]--;
		upd(tab[i]);
		if (tab[i])
		{
			glo=daj(0, 0);
			czyt(1, 1, n1, 1, tab[i]-1);
			//~ debug() << imie(drz[(1+n1-1)/2].wyj);
			//~ debug() << imie(drz[(1+n1-1)].wyj);
			//~ debug() << imie(drz[(2+n1-1)].wyj);
			//~ debug() << i << " " << glo.wyj;
			wyn+=glo.wyj[0].second+1;
		}
		polew[tab[i]]++;
		upd(tab[i]);
	}
	printf("%lld\n", wyn);
	return 0;
}
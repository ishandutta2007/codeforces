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
const int nax=1300*1007;
const int n1=(1<<19);

int n;
int tab[nax];
int zap[nax];

int gdz[nax];

int drznaj[nax];

int wywal[nax];
int wyn;

int narz[nax];
int pod[nax];

void usun(int v)
{
	wywal[v]=1;
	while(wywal[wyn])
		wyn--;
	v=gdz[v];
	v+=n1-1;
	drznaj[v]=0;
	v>>=1;
	while(v)
	{
		drznaj[v]=max(drznaj[v*2], drznaj[v*2+1]);
		v>>=1;
	}
}

int dajnaj(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drznaj[v];
	}
	if (a>grab || b<graa)
	{
		return 0;
	}
	return max(
		dajnaj(v*2, a, (a+b)>>1, graa, grab),
		dajnaj(v*2+1, (a+b+2)>>1, b, graa, grab)
	);
}

int daj(int v)
{
	return narz[v]+pod[v];
}

void upd(int v)
{
	pod[v]=min(daj(v*2), daj(v*2+1));
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

int szukaj(int v, int od, int prz=n1)
{
	if (daj(v)>=od)
		return prz;
	if (prz==1)
		return 0;
	if (daj(v*2)+narz[v]>=od)
		return szukaj(v*2+1, od-narz[v], prz>>1)+(prz>>1);
	return szukaj(v*2, od-narz[v], prz>>1);
}

int main()
{
	scanf("%d", &n);
	wyn=n;
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=1; i<=n; i++)
		scanf("%d", &zap[i]);
	for (int i=1; i<=n; i++)
		gdz[tab[i]]=i;
	for (int i=1; i<=n; i++)
		drznaj[i-1+n1]=tab[i];
	for (int i=n1-1; i; i--)
		drznaj[i]=max(drznaj[i*2], drznaj[i*2+1]);
	printf("%d", n);
	for (int i=1; i<n; i++)
	{
		int v=zap[i];
		pisz(1, 1, n1, 1, v, 1);
		int d=szukaj(1, 1);
		pisz(1, 1, n1, 1, v, -1);
		int x=dajnaj(1, 1, n1, 1, d);
		int g=gdz[x];
		usun(x);
		if (g<v)
			pisz(1, 1, n1, g+1, v, 1);
		if (g>v)
			pisz(1, 1, n1, v+1, g, -1);
		printf(" %d", wyn);
		//~ debug() << imie(v) << imie(d) << imie(x);
	}
	printf("\n");
	return 0;
}
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
const int nax=1000*1007;
const int n1=(1<<18);
const ll inf=1e18;

int n;

ll narz[nax];
pll mini[nax];

int wyn[nax];

pll daj(int v)
{
	return {mini[v].first+narz[v], mini[v].second};
}

void upd(int v)
{
	mini[v]=min(daj(v*2), daj(v*2+1));
}

void dod(int v, int a, int b, int graa, int grab, ll x)
{
	if (a>=graa && b<=grab)
	{
		narz[v]+=x;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	dod((v<<1), a, (a+b)>>1, graa, grab, x);
	dod((v<<1)^1, (a+b+2)>>1, b, graa, grab, x);
	upd(v);
}

void start(int v, int a, int b)
{
	if (a==b)
	{
		mini[v]={0, -b};
		return;
	}
	start((v<<1), a, (a+b)>>1);
	start((v<<1)^1, (a+b+2)>>1, b);
}

int szuk(int v, int a, int b)
{
	if (a==b)
		return a;
	if (daj(v*2)<daj(v*2+1))
		return szuk((v<<1), a, (a+b)>>1);
	return szuk((v<<1)^1, (a+b+2)>>1, b);
}

int main()
{
	scanf("%d", &n);
	start(1, 1, n1);
	dod(1, 1, n1, n+1, n1, inf);
	for (int i=1; i<=n; i++)
	{
		ll x;
		scanf("%lld", &x);
		dod(1, 1, n1, i, i, x);
	}
	for (int h=1; h<=n; h++)
	{
		int v=-mini[1].second;
		wyn[v]=h;
		debug() << imie(v);
		dod(1, 1, n1, v+1, n, -h);
		dod(1, 1, n1, v, v, inf);
	}
	for (int i=1; i<=n; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}
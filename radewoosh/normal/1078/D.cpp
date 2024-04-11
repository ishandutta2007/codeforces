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
const int nax=1107*1007;
const int n1=(1<<19);
const int d=18;

int n;
int tab[nax];
pii prze[d][300*1007];

int drzpra[d][nax];
int drzlew[d][nax];

void piszpra(int kt, int v, int w)
{
	v+=n1-1;
	while(v)
	{
		drzpra[kt][v]=max(drzpra[kt][v], w);
		v>>=1;
	}
}

void piszlew(int kt, int v, int w)
{
	v+=n1-1;
	while(v)
	{
		drzlew[kt][v]=min(drzlew[kt][v], w);
		v>>=1;
	}
}

void zapisz(int v)
{
	for (int i=0; i<nax; i++)
		drzlew[v][i]=nax;
	for (int i=1; i<=3*n; i++)
	{
		piszlew(v, i, prze[v][i].first);
		piszpra(v, i, prze[v][i].second);
	}
}

pii czyt(int kt, int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return {drzlew[kt][v], drzpra[kt][v]};
	}
	if (a>grab || b<graa)
	{
		return {nax, 0};
	}
	pii r1=czyt(kt, (v<<1), a, (a+b)>>1, graa, grab);
	pii r2=czyt(kt, (v<<1)^1, (a+b+2)>>1, b, graa, grab);
	return {min(r1.first, r2.first), max(r1.second, r2.second)};
}

int wsz(pii v)
{
	return (v.second-v.first+1>=n);
}

int main()
{
	scanf("%d", &n);
	if (n==1)
	{
	    printf("0\n");
	    return 0;
	}
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for (int i=n+1; i<=3*n; i++)
		tab[i]=tab[i-n];
	for (int i=1; i<=3*n; i++)
	{
		prze[0][i]={i-tab[i], i+tab[i]};
		prze[0][i].first=max(prze[0][i].first, 1);
		prze[0][i].second=min(prze[0][i].second, 3*n);
	}
	zapisz(0);
	for (int h=1; h<d; h++)
	{
		for (int i=1; i<=3*n; i++)
			prze[h][i]=czyt(h-1, 1, 1, n1, prze[h-1][i].first, prze[h-1][i].second);
		zapisz(h);
		//~ debug() << h << " " << range(prze[h]+1, prze[h]+1+3*n);
	}
	for (int i=1; i<=n; i++)
	{
		int wyn=0;
		pii ter={n+i, n+i};
		for (int j=d-1; j>=0; j--)
		{
			pii now=czyt(j, 1, 1, n1, ter.first, ter.second);
			if (!wsz(now))
			{
				ter=now;
				wyn+=(1<<j);
			}
		}
		printf("%d ", wyn+1);
	}
	printf("\n");
	return 0;
}
//PRZEMYSL ASSERTY

//SPRAWDZ CORNER CASE'Y, MINIMALNE I MAKSYMALNE WEJCIE I WYJCIE

//MODULO = 1

//while (clock()<=69*CLOCKS_PER_SEC)

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

const int nax=200*1007;
const int kax=57;
const int n1=(2<<16);

int n, k;

int tab[nax];

int dp[kax][nax];

int narz[nax];
int drzewo[nax];

pair <int,int> prze[nax];

inline void update(int v)
{
	drzewo[v]=max(drzewo[(v<<1)]+narz[(v<<1)], drzewo[(v<<1)^1]+narz[(v<<1)^1]);
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
	update(v);
}

int czyt(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return narz[v]+drzewo[v];
	}
	if (a>grab || b<graa)
	{
		return -nax;
	}
	return max(
	czyt((v<<1), a, (a+b)>>1, graa, grab),
	czyt((v<<1)^1, (a+b+2)>>1, b, graa, grab))+narz[v];
}

void czys()
{
	for (int i=0; i<nax; i++)
		drzewo[i]=narz[i]=0;
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	for(int h=1; h<=k; h++)
	{
		for (int i=1; i<=n; i++)
			prze[i]={0,0};
		czys();
		for (int i=1; i<=n; i++)
		{
			//debug() << imie(dp[h-1][i-1]);
			pisz(1, 1, n1, i, i, dp[h-1][i-1]);
			int x=tab[i];
			//pisz(1, 1, n1, prze[x].first, prze[x].second, -1);
			prze[x].first=prze[x].second+1;
			prze[x].second=i;
			pisz(1, 1, n1, prze[x].first, prze[x].second, 1);
			
			dp[h][i]=czyt(1, 1, n1, 1, i);
		}
		debug() << range(dp[h]+1, dp[h]+1+n);
	}
	printf("%d\n", dp[k][n]);
	return 0;
}
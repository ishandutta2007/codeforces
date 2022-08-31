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

int n, m;

int tab[nax];

pii prz[nax];

int chcelew[nax];
int chcepra[nax];

int solew[nax];
int sopra[nax];

int zlelew[nax];
int zlepra[nax];

vi polew[nax];
vi popra[nax];

void skaluj()
{
	map<int,int> mapa;
	int w=0;
	for (int i=1; i<=n; i++)
		mapa[tab[i]]=0;
	for (auto i : mapa)
	{
		w++;
		mapa[i.first]=w;
	}
	for (int i=1; i<=n; i++)
		tab[i]=mapa[tab[i]];
}

int robi_zle(int a, int b)
{
	return (a>=chcelew[b]);
}

int check(int v)
{
	for (int i=1; i<=n; i++)
	{
		polew[i].clear();
		popra[i].clear();
	}
	for (int i=n; i>v; i--)
		popra[tab[i]].push_back(i);
	int zle=0;
	for (int i=v; i<=n; i++)
	{
		if (!zlelew[i-v] && !zlepra[i+1] && !zle)
			return 1;
		if (i==n)
			break;
		{
			int x=tab[i+1];
			if (!polew[x].empty() && !popra[x].empty() && robi_zle(polew[x].back(), popra[x].back()))
				zle--;
			popra[x].pop_back();
			if (!polew[x].empty() && !popra[x].empty() && robi_zle(polew[x].back(), popra[x].back()))
				zle++;
		}
		{
			int x=tab[i+1-v];
			if (!polew[x].empty() && !popra[x].empty() && robi_zle(polew[x].back(), popra[x].back()))
				zle--;
			polew[x].push_back(i+1-v);
			if (!polew[x].empty() && !popra[x].empty() && robi_zle(polew[x].back(), popra[x].back()))
				zle++;
		}
	}
	return 0;
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	skaluj();
	for (int i=0; i<=n+1; i++)
		zlelew[i]=zlepra[i]=0;
	for (int i=1; i<=n; i++)
		chcelew[i]=chcepra[i]=i;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		prz[i]={a, b};
		chcelew[b]=min(chcelew[b], a);
		chcepra[a]=max(chcepra[a], b);
	}
	for (int i=n-1; i; i--)
		chcelew[i]=min(chcelew[i], chcelew[i+1]);
	for (int i=2; i<=n; i++)
		chcepra[i]=max(chcepra[i], chcepra[i-1]);
	//~ debug() << range(chcelew+1, chcelew+1+n);
	//~ debug() << range(chcepra+1, chcepra+1+n);
	{
		vi mapa(n+3);
		for (int i=1; i<=n; i++)
		{
			solew[i]=mapa[tab[i]];
			mapa[tab[i]]=i;
		}
		for (int i=1; i<=n; i++)
			mapa[i]=n+1;
		for (int i=n; i; i--)
		{
			sopra[i]=mapa[tab[i]];
			mapa[tab[i]]=i;
		}
	}
	for (int i=1; i<=n; i++)
	{
		if (solew[i]>=chcelew[i])
			zlelew[i]=1;
		if (sopra[i]<=chcepra[i])
			zlepra[i]=1;
	}
	for (int i=1; i<=n; i++)
		zlelew[i]|=zlelew[i-1];
	for (int i=n; i; i--)
		zlepra[i]|=zlepra[i+1];
	//~ debug() << range(zlelew+1, zlelew+1+n);
	//~ debug() << range(zlepra+1, zlepra+1+n);
	int bsa=0;
	int bsb=n;
	while(bsa<bsb)
	{
		int bss=(bsa+bsb)>>1;
		if (check(bss))
			bsb=bss;
		else
			bsa=bss+1;
	}
	printf("%d\n", bsa);
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
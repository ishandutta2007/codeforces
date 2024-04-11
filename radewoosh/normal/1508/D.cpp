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
const int nax=2007;

int n;

pll tab[nax];
int zna[nax];

int cen=0;

vector<pii> wyn;

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

ll ilowek(pll s, pll a, pll b)
{
	a=a-s;
	b=b-s;
	return a.first*b.second-a.second*b.first;
}

bool mniej(int a, int b)
{
	return ilowek(tab[cen], tab[a], tab[b])>0;
}

int oj[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

void koniec()
{
	for (int i=1; i<=n; i++)
		assert(zna[i]==i);
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	exit(0);
}

int zaj[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld%lld%d", &tab[i].first, &tab[i].second, &zna[i]);
	}
	{
		int spoko=1;
		for (int i=1; i<=n; i++)
			if (zna[i]!=i)
				spoko=0;
		if (spoko)
			koniec();
	}
	for (int i=2; i<=n; i++)
		if (i!=zna[i] && (!cen || tab[i]<tab[cen]))
			cen=i;
	vi resz;
	for (int i=1; i<=n; i++)
		if (i!=cen && zna[i]!=i)
			resz.push_back(i);
	sort(resz.begin(), resz.end(), mniej);
	//~ debug() << cen << " " << resz;
	assert(!resz.empty());
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=n; i++)
		uni(i, zna[i]);
	for (int i=0; i+1<(int)resz.size(); i++)
	{
		if (fin(resz[i])!=fin(resz[i+1]))
		{
			zaj[i]=1;
			uni(resz[i], resz[i+1]);
			wyn.push_back({resz[i], resz[i+1]});
			swap(zna[resz[i]], zna[resz[i+1]]);
		}
	}
	while(zna[cen]!=cen)
	{
		int v=zna[cen];
		wyn.push_back({cen, v});
		swap(zna[cen], zna[v]);
	}
	
	
	
	
	printf("%d\n", (int)wyn.size());
	for (pii i : wyn)
		printf("%d %d\n", i.first, i.second);
	return 0;
}
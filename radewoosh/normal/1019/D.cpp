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
const int nax=2007;

int n;
ll pole;
pll tab[nax];
int porz[nax];
int gdz[nax];

vector <pii> wek;

pll operator - (pll a, pll b)
{
	return {a.first-b.first, a.second-b.second};
}

int typ(pll v)
{
	if (v.first>0 || (v.first==0 && v.second>0))
		return 0;
	return 1;
}

bool mniej(pii a, pii b)
{
	pll x=tab[a.second]-tab[a.first];
	pll y=tab[b.second]-tab[b.first];
	int r1=typ(x);
	int r2=typ(y);
	if (r1!=r2)
		return r1<r2;
	ll w=x.first*y.second-y.first*x.second;
	return (w<0);
}

inline ll licz(int a, int b, int c)
{
	pll x=tab[b]-tab[a];
	pll y=tab[c]-tab[a];
	return abs(x.first*y.second-y.first*x.second);
}

int main()
{
	scanf("%d%lld", &n, &pole);
	pole*=2;
	for (int i=1; i<=n; i++)
		scanf("%lld%lld", &tab[i].first, &tab[i].second);
	sort(tab+1, tab+1+n);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++)
			wek.push_back({i, j});
	sort(wek.begin(), wek.end(), mniej);
	for (int i=1; i<=n; i++)
		gdz[i]=porz[i]=i;
	//~ debug() << range(tab+1, tab+1+n);
	//~ debug() << wek;
	for (auto i : wek)
	{
		int a=i.first;
		int b=i.second;
		
		assert(gdz[a]+1==gdz[b]);
		gdz[a]++;
		gdz[b]--;
		porz[gdz[a]]=a;
		porz[gdz[b]]=b;
		if (gdz[a]==n)
			continue;
		int bsa=gdz[a]+1;
		int bsb=n;
		int bss;
		while(bsa<bsb)
		{
			bss=(bsa+bsb)>>1;
			if (licz(a, b, porz[bss])<pole)
				bsa=bss+1;
			else
				bsb=bss;
		}
		if (licz(a, b, porz[bsa])==pole)
		{
			printf("Yes\n");
			printf("%lld %lld\n", tab[a].first, tab[a].second);
			printf("%lld %lld\n", tab[b].first, tab[b].second);
			printf("%lld %lld\n", tab[porz[bsa]].first, tab[porz[bsa]].second);
			return 0;
		}
	}
	printf("No\n");
	return 0;
}
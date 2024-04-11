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
const int nax=107;

int n;
int tab[nax];

vector<vi> wyn;

vi oczysc(vi wek)
{
	vi ret;
	for (int i : wek)
		if (i)
			ret.push_back(i);
	return ret;
}

void zrob(vi wek)
{
	wek=oczysc(wek);
	vector<vi> podz;
	int v=0;
	for (int i : wek)
	{
		vi ter;
		for (int j=0; j<i; j++)
		{
			v++;
			ter.push_back(tab[v]);
		}
		podz.push_back(ter);
	}
	reverse(podz.begin(), podz.end());
	v=0;
	for (vi i : podz)
	{
		for (int j : i)
		{
			v++;
			tab[v]=j;
		}
	}
	wyn.push_back(wek);
}

int sor()
{
	for (int i=1; i<n; i++)
		if (tab[i]>tab[i+1])
			return 0;
	return 1;
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		scanf("%d", &tab[i]);
	
	while(!sor())
	{
		debug() << range(tab+1, tab+1+n);
		int moze=1;
		int gm, gn;
		while(1)
		{
			for (int i=1; i<=n; i++)
			{
				if (tab[i]==moze)
					gm=i;
				if (tab[i]==moze+1)
					gn=i;
			}
			if (gn>gm)
			{
				moze++;
				continue;
			}
			break;
		}
		debug() << imie(moze);
		int tnij=gn;
		while(tab[tnij+1]==tab[tnij]+1)
			tnij++;
		zrob({gn-1, tnij-gn+1, gm-tnij, n-gm});
	}
	
	printf("%d\n", (int)wyn.size());
	for (vi i : wyn)
	{
		printf("%d", (int)i.size());
		for (int j : i)
			printf(" %d", j);
		printf("\n");
	}
	return 0;
}
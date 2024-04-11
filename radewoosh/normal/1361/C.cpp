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
const int nax=(1<<20);

int n;

int tab[nax][2];
int pom[nax];

int juz[nax];

vector<pii> graf[nax];

vi wyn;

int dru(int v)
{
	if (v&1)
		return v+1;
	return v-1;
}

int gr(int v)
{
	return (v+1)>>1;
}

void dfs(int v)
{
	while(!graf[v].empty())
	{
		int u=graf[v].back().first;
		int c=graf[v].back().second;
		graf[v].pop_back();
		if (juz[gr(c)])
			continue;
		juz[gr(c)]=1;
		dfs(u);
		wyn.push_back(dru(c));
		wyn.push_back(c);
	}
}

void proba(int v)
{
	int xo=0;
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			xo^=tab[i][j];
	if (xo)
		return;
	for (int i=1; i<=n; i++)
		juz[i]=0;
	for (int i=0; i<(1<<v); i++)
		graf[i].clear();
	for (int i=1; i<=n; i++)
	{
		int x=tab[i][0];
		int y=tab[i][1];
		graf[x].push_back({y, 2*i-1});
		graf[y].push_back({x, 2*i});
	}
	for (int i=0; i<(1<<v); i++)
		if (graf[i].size()&1)
			return;
	wyn.clear();
	int s=0;
	while(graf[s].empty())
		s++;
	dfs(s);
	if ((int)wyn.size()!=2*n)
		return;
	printf("%d\n", v);
	for (int i : wyn)
		printf("%d ", i);
	printf("\n");
	exit(0);
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=0; j<2; j++)
			scanf("%d", &tab[i][j]);
	for (int h=20; h>=0; h--)
	{
		proba(h);
		assert(h);
		for (int i=1; i<=n; i++)
			for (int j=0; j<2; j++)
				tab[i][j]%=(1<<(h-1));
	}
	return 0;
}
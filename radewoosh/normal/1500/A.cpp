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
const int nax=5000*1007;

int n;

int tab[nax];

vi gdz[nax];
vi jest;

void tak(vi wek)
{
	printf("YES\n");
	for (int i : wek)
		printf("%d ", i);
	printf("\n");
	exit(0);
}

pii widz[nax];

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
	}
	for (int i=1; i<=n; i++)
		gdz[tab[i]].push_back(i);
	for (int i=1; i<nax; i++)
		if (!gdz[i].empty())
			jest.push_back(i);
	vi duz;
	for (int i=0; i<(int)jest.size(); i++)
	{
		int v=jest[i];
		if ((int)gdz[v].size()>=4)
			tak({gdz[v][0], gdz[v][1], gdz[v][2], gdz[v][3]});
		if ((int)gdz[v].size()>=2)
			duz.push_back(v);
	}
	if ((int)duz.size()>=2)
	{
		int a=duz[0];
		int b=duz[1];
		tak({gdz[a][0], gdz[b][0], gdz[a][1], gdz[b][1]});
	}
	if ((int)duz.size()>=1)
	{
		int v=duz[0];
		for (int i : jest)
		{
			int j=2*v-i;
			if (j>=0 && j<nax && j!=i && j!=v && !gdz[j].empty())
				tak({gdz[v][0], gdz[v][1], gdz[i][0], gdz[j][0]});
		}
	}
	for (int i=0; i<(int)jest.size(); i++)
	{
		for (int j=0; j<i; j++)
		{
			int a=jest[i];
			int b=jest[j];
			int s=a+b;
			if (widz[s].first)
			{
				int x=widz[s].first;
				int y=widz[s].second;
				tak({gdz[a][0], gdz[b][0], gdz[x][0], gdz[y][0]});
			}
			widz[s]={jest[i], jest[j]};
		}
	}
	printf("NO\n");
	return 0;
}
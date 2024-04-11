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

void ff()
{
	fflush(stdout);
}

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=1000*1007;

int n;
char wcz[nax];

int dzie[nax][2];
int fun[nax];
int war[nax];

int oj[nax*3];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int v, int u)
{
	oj[fin(v)]=fin(u);
}

int zrob(int a, int b, int typ)
{
	if (typ==1)
		return (a&b);
	if (typ==2)
		return (a|b);
	if (typ==3)
		return (a^b);
}

void dfs1(int v)
{
	if (fun[v]==4)
		return;
	if (fun[v]==5)
	{
		dfs1(dzie[v][0]);
		war[v]=!war[dzie[v][0]];
		return;
	}
	for (int i=0; i<2; i++)
		dfs1(dzie[v][i]);
	war[v]=zrob(war[dzie[v][0]], war[dzie[v][1]], fun[v]);
}

void dfs2(int v)
{
	if (fun[v]==4)
	{
		uni(2*n+v, 2*(v-1)+(!war[v]));
		return;
	}
	if (fun[v]==5)
	{
		dfs2(dzie[v][0]);
		uni(2*(v-1)+0, 2*(dzie[v][0]-1)+1);
		uni(2*(v-1)+1, 2*(dzie[v][0]-1)+0);
		return;
	}
	for (int i=0; i<2; i++)
		dfs2(dzie[v][i]);
	for (int i=0; i<2; i++)
	{
		for (int j=0; j<2; j++)
		{
			uni(2*(dzie[v][i]-1)+j, 2*(v-1)+zrob(j, war[dzie[v][i^1]], fun[v]));
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz);
		if (wcz[0]=='A')
		{
			scanf("%d%d", &dzie[i][0], &dzie[i][1]);
			fun[i]=1;
		}
		if (wcz[0]=='O')
		{
			scanf("%d%d", &dzie[i][0], &dzie[i][1]);
			fun[i]=2;
		}
		if (wcz[0]=='X')
		{
			scanf("%d%d", &dzie[i][0], &dzie[i][1]);
			fun[i]=3;
		}
		if (wcz[0]=='I')
		{
			scanf("%d", &war[i]);
			fun[i]=4;
		}
		if (wcz[0]=='N')
		{
			scanf("%d", &dzie[i][0]);
			fun[i]=5;
		}
	}
	dfs1(1);
	for (int i=0; i<3*nax; i++)
		oj[i]=i;
	dfs2(1);
	for (int i=1; i<=n; i++)
	{
		if (fun[i]==4)
		{
			if (fin(2*n+i)==fin(0))
				printf("0");
			else
				printf("1");
		}
	}
	printf("\n");
	return 0;
}
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

pii tab[nax];

int wyn[2][nax];

vi graf[nax];

int sto[nax];

int ost[nax];
int czas;

int nie[nax];

int bylo[nax];

vi wcho[nax];

int k;

int juz[nax];

void oznacz(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	for (int i : wcho[v])
		oznacz(i);
}

void lacz(int v, vi wek)
{
	//~ debug() << v << " " << wek;
	juz[v]=1;
	for (int i : wek)
		juz[i]=1;
	int r=wek.size();
	wyn[0][v]=k+1;
	wyn[1][v]=k+r+1;
	for (int i : wek)
	{
		k++;
		wyn[0][i]=k+1;
		wyn[1][i]=k;
	}
	k++;
}

void dfs(int v, int oj)
{
	vi ter;
	for (int i : wcho[v])
	{
		if (i==oj)
			continue;
		dfs(i, v);
		if (!juz[i])
			ter.push_back(i);
	}
	if (!ter.empty())
		lacz(v, ter);
}

void ogar(int v)
{
	int u=nie[v];
	vi a, b;
	for (int i : wcho[v])
	{
		if (i==u)
			continue;
		dfs(i, v);
		if (!juz[i])
			a.push_back(i);
	}
	for (int i : wcho[u])
	{
		if (i==v)
			continue;
		dfs(i, u);
		if (!juz[i])
			b.push_back(i);
	}
	if (a.empty())
	{
		b.push_back(v);
		lacz(u, b);
		return;
	}
	if (b.empty())
	{
		a.push_back(u);
		lacz(v, a);
		return;
	}
	lacz(v, a);
	lacz(u, b);
}

void test()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
		scanf("%d%d", &tab[i].first, &tab[i].second);
	for (int i=1; i<=n; i++)
	{
		graf[i].clear();
		ost[i]=0;
		nie[i]=0;
		bylo[i]=0;
		wcho[i].clear();
		juz[i]=0;
	}
	for (int i=1; i<=m; i++)
	{
		graf[tab[i].first].push_back(tab[i].second);
		graf[tab[i].second].push_back(tab[i].first);
	}
	czas=0;
	k=0;
	for (int i=1; i<=n; i++)
	{
		sto[i]=graf[i].size();
		if (sto[i]==n-1)
		{
			k++;
			wyn[0][i]=wyn[1][i]=k;
			continue;
		}
		czas++;
		for (int j : graf[i])
			ost[j]=czas;
		ost[i]=czas;
		for (int j=1; j<=n; j++)
		{
			if (ost[j]!=czas)
			{
				nie[i]=j;
				wcho[j].push_back(i);
				break;
			}
		}
	}
	//~ debug() << range(nie+1, nie+1+n);
	for (int i=1; i<=n; i++)
	{
		if (!nie[i] || bylo[i])
			continue;
		czas++;
		int v=i;
		int osti=0;
		while(ost[v]!=czas)
		{
			ost[v]=czas;
			osti=v;
			v=nie[v];
		}
		oznacz(v);
		nie[v]=osti;
	}
	for (int i=1; i<=n; i++)
	{
		wcho[i].clear();
		bylo[i]=0;
	}
	for (int i=1; i<=n; i++)
	{
		if (!nie[i])
			continue;
		if (nie[nie[i]]!=i)
		{
			wcho[i].push_back(nie[i]);
			wcho[nie[i]].push_back(i);
			continue;
		}
		wcho[i].push_back(nie[i]);
	}
	for (int i=1; i<=n; i++)
	{
		if (!nie[i] || juz[i])
			continue;
		ogar(i);
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << nie[i] << " " << wcho[i];
	
	for (int h=0; h<2; h++)
	{
		for (int i=1; i<=n; i++)
			printf("%d ", wyn[h][i]);
		printf("\n");
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
		test();
	return 0;
}
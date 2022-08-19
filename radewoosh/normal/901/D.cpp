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
  for (auto it = d.b; it != d.e; ++it) 
    *this << ", \0[" + 3 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};

#define imie(x) "[" << #x ": " << (x) << "] "

#define shandom_ruffle random_shuffle

const int nax=1000*1007;

int n, m;

long long tab[nax];

vector < pair <int,int> > graf[nax];

long long wyn[nax];

void nope()
{
	printf("NO\n");
	exit(0);
}

void yep()
{
	printf("YES\n");
	for (int i=1; i<=m; i++)
		printf("%lld\n", wyn[i]);
	exit(0);
}

int bylo[nax];
int parz[nax];
int odl[nax];

vector <int> niep;
int gdz;

int oj[nax];
int kra[nax];

void dfs(int v)
{
	bylo[v]=1;
	for (auto i : graf[v])
	{
		if (bylo[i.first])
		{
			if (odl[i.first]<odl[v] && parz[i.first]==parz[v] && niep.empty())
			{
				int u=v;
				niep.push_back(i.second);
				gdz=i.first;
				while(u!=i.first)
				{
					niep.push_back(kra[u]);
					u=oj[u];
				}
			}
			continue;
		}
		oj[i.first]=v;
		kra[i.first]=i.second;
		odl[i.first]=odl[v]+1;
		parz[i.first]=parz[v]^1;
		dfs(i.first);
	}
}

void dfs2(int v)
{
	bylo[v]=1;
	for (auto i : graf[v])
	{
		if (bylo[i.first])
			continue;
		dfs2(i.first);
		tab[v]-=tab[i.first];
		wyn[i.second]+=tab[i.first];
		tab[i.first]=0;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		scanf("%lld", &tab[i]);
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back({b, i});
		graf[b].push_back({a, i});
	}
	odl[1]=1;
	
	dfs(1);
	memset(bylo, 0, sizeof(bylo));
	
	if (niep.empty())
	{
		dfs2(1);
	}
	else
	{
		dfs2(gdz);
		debug() << range(tab+1, tab+1+n) << " " << gdz << " " << niep;
		assert(!(tab[gdz]%2));
		long long zbi=tab[gdz]/2;
		for (int i=0; i<(int)niep.size(); i++)
		{
			if (!(i&1))
			{
				wyn[niep[i]]+=zbi;
			}
			else
			{
				wyn[niep[i]]-=zbi;
			}
		}
		tab[gdz]=0;
	}
	
	for (int i=1; i<=n; i++)
		if (tab[i])
			nope();
	yep();
	return 0;
}
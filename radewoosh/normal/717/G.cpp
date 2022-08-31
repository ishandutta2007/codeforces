#ifndef LOCAL
#define NDEBUG
#endif

#include <bits/stdc++.h>
using namespace std;

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

struct kra
{
	int cel;
	int* prze1;
	int* prze2;
	long long koszt;
};

int n1;

const int nax=1007;
const long long inf=1000000007;
const long long infinf=inf*inf;

vector <kra> graf[nax];

void add_edge(int v, int u, int prze, long long koszt)
{
	kra ret1{u, new int, new int, koszt};
	kra ret2{v, ret1.prze2, ret1.prze1, -koszt};
	
	(*ret1.prze1)=prze;
	(*ret1.prze2)=0;
	
	graf[v].push_back(ret1);
	graf[u].push_back(ret2);
}

int aktu[nax];
long long odl[nax];

int bylo[nax];

queue <int> bfs;

vector <int> drzewo[nax];
int ojc[nax];

long long wyn;

void tnij(int v)
{
	debug() << "tne " << v;
	ojc[v]=0;
	for (int i=0; i<drzewo[v].size(); i++)
		if (ojc[drzewo[v][i]]==v)
			tnij(drzewo[v][i]);
	drzewo[v].clear();
	aktu[v]=1;
}

void spfa()
{
	for (int i=1; i<=n1; i++)
	{
		aktu[i]=1;
		odl[i]=infinf;
		drzewo[i].clear();
		ojc[i]=0;
	}
	aktu[1]=0;
	odl[1]=0;
	bfs.push(1);
	while(!bfs.empty())
	{
		int v=bfs.front();
		bfs.pop();
		if (aktu[v])
			continue;
		aktu[v]=1;
		for (int i=0; i<graf[v].size(); i++)
		{
			if ((*graf[v][i].prze1) && odl[v]+graf[v][i].koszt<odl[graf[v][i].cel])
			{
				debug() << "ciecie";
				tnij(graf[v][i].cel);
				ojc[graf[v][i].cel]=v;
				drzewo[v].push_back(graf[v][i].cel);
				
				odl[graf[v][i].cel]=odl[v]+graf[v][i].koszt;
				aktu[graf[v][i].cel]=0;
				bfs.push(graf[v][i].cel);
			}
		}
	}
	debug() << range(odl+1, odl+1+n1);
}

int dfs(int v)
{
	debug() << imie(v);
	if (v==n1)
		return 1;
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		debug() << "z " << v << " na " << graf[v][i].cel;
		if (!bylo[graf[v][i].cel] && (*graf[v][i].prze1) && odl[v]+graf[v][i].koszt==odl[graf[v][i].cel] && dfs(graf[v][i].cel))
		{
			wyn+=graf[v][i].koszt;
			(*graf[v][i].prze1)--;
			(*graf[v][i].prze2)++;
			return 1;
		}
	}
	return 0;
}

int flow()
{
	spfa();
	for (int i=1; i<=n1; i++)
		bylo[i]=0;
	debug() << "jade";
	return dfs(1);
}


int n, m, x;

char tek[nax];
char slo[nax];
int dlu[nax];

int tab[nax][nax];

int main()
{
	scanf("%d", &n);
	scanf("%s", tek+1);
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%s", slo+1);
		int p1;
		scanf("%d", &p1);
		dlu[i]=strlen(slo+1);
		for (int j=1; j+dlu[i]-1<=n; j++)
		{
			tab[j][i]=p1;
			for (int l=dlu[i]; l; l--)
				if (slo[l]!=tek[j-1+l])
					tab[j][i]=0;
		}
	}
	scanf("%d", &x);
	for (int i=1; i<=n; i++)
		debug() << range(tab[i]+1, tab[i]+1+n);
	n1=n+1;
	for (int i=1; i<=n; i++)
	{
		add_edge(i, i+1, x, 0);
		for (int j=1; j<=m; j++)
			add_edge(i, i+dlu[j], 1, -tab[i][j]);
	}
	for (int i=1; i<=x; i++)
		flow();
	printf("%lld\n", -wyn);
	return 0;
}
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

const int nax=200*1007;
const int inf=1007*1007*1007;

int n, m;

pair <int,int> kra[nax];
int dlu[nax];
vector < pair <int,int> > graf[nax];
int drz[nax];
int odl[nax];

int dos[nax];

int wyn[nax];

int ojf[nax];

int wgo[nax];
vector < pair <int,int> > jump[nax];

int fin(int v)
{
	if (v!=ojf[v])
		ojf[v]=fin(ojf[v]);
	return ojf[v];
}

void uni(int v, int u)
{
	v=fin(v);
	u=fin(u);
	ojf[v]=u;
}

bool mniej(int a, int b)
{
	return dlu[a]<dlu[b];
}

void dfs(int v, int ojk, int ojw)
{
	wgo[v]=ojk;
	jump[v].push_back({ojw, dlu[ojk]});
	while(jump[v].back().first)
	{
		int p1=jump[v].back().first;
		int p2=min(jump[v].size(), jump[p1].size())-1;
		int p3=jump[p1][p2].first;
		int war=max(jump[v].back().second, jump[p1][p2].second);
		jump[v].push_back({p3, war});
	}
	
	for (auto i : graf[v])
	{
		if (i.first==ojw)
			continue;
		odl[i.first]=odl[v]+1;
		dfs(i.first, i.second, v);
	}
}

int getmax(int v, int u)
{
	int ret=0;
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[v].size() && odl[jump[v][i].first]>=odl[u])
		{
			ret=max(ret, jump[v][i].second);
			v=jump[v][i].first;
		}
	}
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[u].size() && odl[jump[u][i].first]>=odl[v])
		{
			ret=max(ret, jump[u][i].second);
			u=jump[u][i].first;
		}
	}
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[u].size() && jump[u][i].first!=jump[v][i].first)
		{
			ret=max(ret, jump[u][i].second);
			ret=max(ret, jump[v][i].second);
			u=jump[u][i].first;
			v=jump[v][i].first;
		}
	}
	if (v!=u)
	{
		ret=max(ret, jump[v][0].second);
		ret=max(ret, jump[u][0].second);
	}
	return ret-1;
}

int upd(int &v, int w)
{
	v=min(v, w);
}

void piszmin(int v, int u, int w)
{
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[v].size() && odl[jump[v][i].first]>=odl[u])
		{
			upd(jump[v][i].second, w);
			v=jump[v][i].first;
		}
	}
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[u].size() && odl[jump[u][i].first]>=odl[v])
		{
			upd(jump[u][i].second, w);
			u=jump[u][i].first;
		}
	}
	for (int i=20; i>=0; i--)
	{
		if (i<(int)jump[u].size() && jump[u][i].first!=jump[v][i].first)
		{
			upd(jump[v][i].second, w);
			upd(jump[u][i].second, w);
			u=jump[u][i].first;
			v=jump[v][i].first;
		}
	}
	if (v!=u)
	{
		upd(jump[v][0].second, w);
		upd(jump[u][0].second, w);
	}
}


void dfs2(int v, int oj)
{
	debug() << "jade " << v;
	for (auto i : graf[v])
	{
		if (i.first==oj)
			continue;
		dfs2(i.first, v);
	}
	for (int i=(int)jump[v].size()-1; i>0; i--)
	{
		upd(jump[v][i-1].second, jump[v][i].second);
		int p1=jump[v][i-1].first;
		int p2=min(i, (int)jump[p1].size())-1;
		upd(jump[p1][p2].second, jump[v][i].second);
	}
	wyn[wgo[v]]=jump[v][0].second;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++)
		ojf[i]=i;
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &kra[i].first, &kra[i].second, &dlu[i]);
		dos[i]=i;
		wyn[i]=inf;
	}
	sort(dos+1, dos+1+m, mniej);
	for (int i=1; i<=m; i++)
	{
		int v=dos[i];
		if (fin(kra[v].first)==fin(kra[v].second))
			continue;
		uni(kra[v].first, kra[v].second);
		drz[v]=1;
		graf[kra[v].first].push_back({kra[v].second, v});
		graf[kra[v].second].push_back({kra[v].first, v});
	}
	odl[1]=1;
	dfs(1, 0, 0);
	for (int i=1; i<=n; i++)
		debug() << i << " " << jump[i];
	
	for (int i=1; i<=m; i++)
		if (!drz[i])
			wyn[i]=getmax(kra[i].first, kra[i].second);
	
	for (int i=1; i<=n; i++)
		for (int j=0; j<(int)jump[i].size(); j++)
			jump[i][j].second=inf;
	
	for (int i=1; i<=m; i++)
		if (!drz[i])
			piszmin(kra[i].first, kra[i].second, dlu[i]-1);
	dfs2(1, 0);
	
	for (int i=1; i<=m; i++)
		if (wyn[i]==inf)
			wyn[i]=-1;
	for (int i=1; i<=m; i++)
		printf("%d ", wyn[i]);
	printf("\n");
	return 0;
}
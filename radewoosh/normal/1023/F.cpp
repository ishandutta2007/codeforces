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
const int nax=1000*1007;
const ll inf=1007*1007*1007;

int n, k, m;

vi graf[nax];

vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax];
int l;

void dfs_roz(int v)
{
	roz[v]=1;
	for (int &i : drz[v])
	{
		fad[i]=v;
		dfs_roz(i);
		roz[v]+=roz[i];
		if (roz[i]>roz[drz[v][0]])
			swap(i, drz[v][0]);
	}
}

void dfs_pre(int v)
{
	if (!jump[v])
		jump[v]=v;
	l++;
	pre[v]=l;
	if (!drz[v].empty())
		jump[drz[v][0]]=jump[v];
	for (int i : drz[v])
		dfs_pre(i);
	post[v]=l;
}

int lca(int v, int u)
{
	while(jump[v]!=jump[u])
	{
		if (pre[v]<pre[u])
			swap(v, u);
		v=fad[jump[v]];
	}
	return (pre[v]<pre[u] ? v : u);
}

vector < pair <int,int> > path_up(int v, int u)
{
	vector < pair <int,int> > ret;
	while(jump[v]!=jump[u])
	{
		ret.push_back({pre[jump[v]], pre[v]});
		v=fad[jump[v]];
	}
	ret.push_back({pre[u], pre[v]});
	return ret;
}

vector < pair <int,int> > get_path(int v, int u)
{
	int w=lca(v, u);
	auto ret=path_up(v, w);
	auto pom=path_up(u, w);
	for (auto &i : ret)
		swap(i.first, i.second);
	while(!pom.empty())
	{
		ret.push_back(pom.back());
		pom.pop_back();
	}
	return ret;
}

int num;
int bylo[nax];

void dfs1(int v, int oj)
{
	bylo[v]=num;
	for (int i : graf[v])
	{
		if (i!=oj)
		{
			dfs1(i, v);
			drz[v].push_back(i);
		}
	}
}

void ans(ll v)
{
	printf("%lld\n", v);
	exit(0);
}

set <pii> down;

vi korz;

ll wyn;

ll ogr[nax];

void dfs2(int v)
{
	debug() << v;
	for (int i : drz[v])
	{
		dfs2(i);
		if (!down.count({v, i}))
		{
			if (ogr[i]==inf)
				ans(-1);
			wyn+=ogr[i];
		}
	}
}

int oj[nax];

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void znacz(int a, int b, ll w)
{
	//~ int li=0;
	while(pre[a]>pre[b])
	{
		//~ li++;
		//~ if (li==5)
			//~ exit(0);
		//~ debug() << a << " " << b;
		if (a!=fin(a))
		{
			a=fin(a);
			continue;
		}
		ogr[a]=w;
		oj[a]=fad[a];
	}
	//~ debug() << "kon";
}

int main()
{
	scanf("%d%d%d", &n, &k, &m);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int i=1; i<=k; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
		oj[fin(a)]=fin(b);
	}
	vector <pii> pam;
	vll war;
	for (int i=1; i<=m; i++)
	{
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		pam.push_back({a, b});
		war.push_back(c);
		int x=fin(a);
		int y=fin(b);
		if (x!=y)
		{
			down.insert({a, b});
			down.insert({b, a});
			graf[a].push_back(b);
			graf[b].push_back(a);
			oj[x]=y;
		}
	}
	dfs1(1, 0);
	dfs_roz(1);
	dfs_pre(1);
	
	for (int i=1; i<=n; i++)
	{
		oj[i]=i;
		ogr[i]=inf;
	}
	
	
	
	for (int i=0; i<m; i++)
	{
		int a=pam[i].first;
		int b=pam[i].second;
		ll c=war[i];
		int p=lca(a, b);
		debug() << a << " " << b << "  " << p;
		znacz(a, p, c);
		znacz(b, p, c);
	}
	dfs2(1);
	ans(wyn);
	return 0;
}
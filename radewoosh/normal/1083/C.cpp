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
const int nax=1200*1007;
const int n1=(1<<18);

int n;
int tab[nax];
int gdz[nax];

vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax];
int odl[nax];
int l;

void dfs_roz(int v)
{
	roz[v]=1;
	for (int &i : drz[v])
	{
		fad[i]=v;
		odl[i]=odl[v]+1;
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

int liczodl(int a, int b)
{
	return odl[a]+odl[b]-2*odl[lca(a, b)];
}

pii prze[nax];

int mac[4][4];

pii lacz(pii a, pii b)
{
	if (a.first==0)
		return b;
	if (a.first==-1)
		return a;
	if (b.first==-1)
		return b;
	vi wek{a.first, a.second, b.first, b.second};
	pii naj={0, 0};
	for (int i=0; i<4; i++)
	{
		for (int j=0; j<i; j++)
		{
			mac[i][j]=mac[j][i]=liczodl(wek[i], wek[j]);
			if (mac[i][j]>mac[naj.first][naj.second])
				naj={i, j};
		}
	}
	for (int i=0; i<4; i++)
		if (mac[naj.first][i]+mac[naj.second][i]!=mac[naj.first][naj.second])
			return {-1, -1};
	return {wek[naj.first], wek[naj.second]};
}

void upd(int v)
{
	prze[v+n1-1]={gdz[v], gdz[v]};
	v+=n1-1;
	v>>=1;
	while(v)
	{
		prze[v]=lacz(prze[v*2], prze[v*2+1]);
		v>>=1;
	}
}

void zamien(int a, int b)
{
	int x=tab[a];
	int y=tab[b];
	swap(tab[a], tab[b]);
	swap(gdz[x], gdz[y]);
	upd(x);
	upd(y);
}

int wyn;
pii juz;

int lis;

void szuk(int v, int a, int b)
{
	if (a==b)
		return;
	int s=(a+b)>>1;
	if (s>n)
	{
		szuk(v<<1, a, (a+b)>>1);
		return;
	}
	pii wez=lacz(juz, prze[v*2]);
	if (wez.first!=-1)
	{
		juz=wez;
		wyn+=s-a+1;
		szuk((v<<1)^1, (a+b+2)>>1, b);
	}
	else
	{
		szuk(v<<1, a, (a+b)>>1);
	}
}

void query()
{
	int typ;
	scanf("%d", &typ);
	if (typ==1)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		zamien(a, b);
	}
	else
	{
		if (lis==2)
		{
			printf("%d\n", n);
			return;
		}
		juz={0, 0};
		wyn=0;
		szuk(1, 1, n1);
		printf("%d\n", wyn);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &tab[i]);
		tab[i]++;
		gdz[tab[i]]=i;
	}
	for (int i=2; i<=n; i++)
	{
		int x;
		scanf("%d", &x);
		drz[x].push_back(i);
	}
	for (int i=1; i<=n; i++)
	{
		int sto=((i>1)+(!drz[i].empty()));
		lis+=(sto==1);
	}
	odl[1]=1;
	dfs_roz(1);
	dfs_pre(1);
	for (int i=1; i<=n; i++)
		prze[i+n1-1]={gdz[i], gdz[i]};
	for (int i=n1-1; i; i--)
		prze[i]=lacz(prze[i*2], prze[i*2+1]);
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}
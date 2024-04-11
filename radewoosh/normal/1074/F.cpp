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
const int nax=1100*1007;
const int n1=(1<<18);

int n, q;
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

int odl[nax];
vi jumpp[nax];

void dfs1(int v, int oj)
{
	jumpp[v].push_back(oj);
	while(jumpp[v].back())
	{
		int p1=jumpp[v].back();
		int p2=min(jumpp[v].size(), jumpp[p1].size())-1;
		jumpp[v].push_back(jumpp[p1][p2]);
	}
	for (int i : graf[v])
	{
		if (i!=oj)
		{
			odl[i]=odl[v]+1;
			drz[v].push_back(i);
			dfs1(i, v);
		}
	}
}

int skocz(int v, int ile)
{
	for (int i=0; (1<<i)<=ile; i++)
		if (ile&(1<<i))
			v=jumpp[v][i];
	return v;
}

int dod[nax];
pii maxi[nax];

pii lacz(pii a, pii b)
{
	if (a.first==b.first)
		return {a.first, a.second+b.second};
	return max(a, b);
}

pii daj(int v)
{
	return {dod[v]+maxi[v].first, maxi[v].second};
}

void upd(int v)
{
	maxi[v]=lacz(daj(v*2), daj(v*2+1));
}

void pisz(int v, int a, int b, int graa, int grab, int w)
{
	//~ if (v==1)
		//~ debug() << "pisze " << graa << " " << grab << "  " << w;
	if (a>=graa && b<=grab)
	{
		dod[v]+=w;
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	pisz((v<<1), a, (a+b)>>1, graa, grab, w);
	pisz((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
	upd(v);
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	odl[1]=1;
	dfs1(1, 0);
	dfs_roz(1);
	dfs_pre(1);
	set <pii> jest;
	for (int i=1; i<=n; i++)
		maxi[i+n1-1]={0, 1};
	for (int i=n1-1; i; i--)
		upd(i);
	pisz(1, 1, n1, n+1, n1, -1);
	while(q--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a>b)
			swap(a, b);
		int w;
		if (jest.count({a, b}))
		{
			w=-1;
			jest.erase({a, b});
		}
		else
		{
			w=1;
			jest.insert({a, b});
		}
		int l=lca(a, b);
		//~ debug() << a << " " << b << " " << l;
		if (a!=l && b!=l)
		{
			pisz(1, 1, n1, pre[a], post[a], w);
			pisz(1, 1, n1, pre[b], post[b], w);
		}
		else
		{
			if (l==b)
				swap(a, b);
			pisz(1, 1, n1, 1, n, w);
			int p=skocz(b, odl[b]-odl[a]-1);
			pisz(1, 1, n1, pre[p], post[p], -w);
			pisz(1, 1, n1, pre[b], post[b], w);
		}
		pii v=daj(1);
		if (v.first!=(int)jest.size())
			v.second=0;
		//~ debug() << v;
		printf("%d\n", v.second);
	}
	return 0;
}
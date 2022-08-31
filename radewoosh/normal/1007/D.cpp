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
const int nax=1000*1007;
const int n1=(1<<17);

int n, m;

vector <int> graf[nax];

pii lubi[nax][2];

int k;
int numy[nax][2];

int ojc[nax];
int odl[nax];

pii prze[nax];
int wsp[nax];

vector<int> drz[nax];
int prel, roz[nax], jump[nax], pre[nax], post[nax], fad[nax];
void dfs_roz(int v) {
  roz[v] = 1;
  for (int& i : drz[v]) {
    fad[i] = v;
    dfs_roz(i);
    roz[v] += roz[i];
    if (roz[i] > roz[drz[v][0]]) swap(i, drz[v][0]);
  }
}
void dfs_pre(int v) {
  if (!jump[v]) jump[v] = v;
  pre[v] = ++prel;
  if (!drz[v].empty()) jump[drz[v][0]] = jump[v];
  for (int i : drz[v]) dfs_pre(i);
  post[v] = prel;
}
int lca(int v, int u) {
  while (jump[v] != jump[u]) {
    if (pre[v] < pre[u]) swap(v, u);
    v = fad[jump[v]];
  }
  return (pre[v] < pre[u] ? v : u);
}
vector<pair<int, int>> path_up(int v, int u) {
  vector<pair<int, int>> ret;
  while (jump[v] != jump[u]) {
    ret.emplace_back(pre[jump[v]], pre[v]);
    v = fad[jump[v]];
  }
  ret.emplace_back(pre[u], pre[v]);
  return ret;
}
vector<pair<int, int>> get_path(int v, int u) {
  int w = lca(v, u);
  auto ret = path_up(v, w);
  auto pom = path_up(u, w);
  //~ for (auto& i : ret) swap(i.first, i.second);
  while (!pom.empty()) {
    ret.push_back(pom.back());
    pom.pop_back();
  }
  return ret;
}


void dfs1(int v, int oj)
{
	for (int i : graf[v])
	{
		if (i!=oj)
		{
			ojc[i]=v;
			odl[i]=odl[v]+1;
			drz[v].push_back(i);
			dfs1(i, v);
		}
	}
}

vector <int> smie1[nax];
vector <int> smie2[nax];

void rzuc(int v, int a, int b, int graa, int grab, int war)
{
	if (graa>grab)
		return;
	if (a>grab || b<graa)
	{
		return;
	}
	smie2[v].push_back(war);
	if (a>=graa && b<=grab)
	{
		smie1[v].push_back(war);
		return;
	}
	rzuc((v<<1), a, (a+b)>>1, graa, grab, war);
	rzuc((v<<1)^1, (a+b+2)>>1, b, graa, grab, war);
}

int l;
int mypost[nax];
int bylo[nax];

int spo[nax];

int daj(int v, int a, int b, int graa, int grab, int roz)
{
	if (a>grab || b<graa || grab<graa)
		return -1;
	for (int &i : smie1[v])
	{
		if (i!=roz)
		{
			int x=i;
			swap(i, smie1[v].back());
			smie1[v].pop_back();
			return x;
		}
	}
	if (a>=graa && b<=grab)
	{
		for (int &i : smie2[v])
		{
			if (i!=roz)
			{
				int x=i;
				swap(i, smie2[v].back());
				smie2[v].pop_back();
				return x;
			}
		}
		return -1;
	}
	int x;
	x=daj((v<<1), a, (a+b)>>1, graa, grab, roz);
	if (x!=-1)
		return x;
	x=daj((v<<1)^1, (a+b+2)>>1, b, graa, grab, roz);
	if (x!=-1)
		return x;
	return -1;
}

int pas(int v)
{
	if (v&1)
		return v+1;
	return v-1;
}

void dfs2(int v)
{
	if (bylo[v])
		return;
	bylo[v]=1;
	
	auto wez=get_path(prze[v].first, prze[v].second);
	//~ debug() << wez;
	for (auto i : wez)
	{
		if (i.first==pre[wsp[v]])
			i.first++;
		if (i.second<i.first)
			continue;
		//~ debug() << v << " na " << i;
		while(1)
		{
			int x=daj(1, 1, n1, i.first, i.second, v);
			if (x==-1)
				break;
			//~ debug() << "z " << v << " do " << pas(x);
			dfs2(pas(x));
		}
	}
	l++;
	mypost[l]=v;
	//~ debug() << "wychodze " << v;
}

int znacz[nax];

void dfs3(int v)
{
	if (spo[v])
		return;
	spo[v]=l;
	auto wez=get_path(prze[pas(v)].first, prze[pas(v)].second);
	//~ debug() << wez;
	for (auto i : wez)
	{
		if (i.first==pre[wsp[pas(v)]])
			i.first++;
		if (i.second<i.first)
			continue;
		while(1)
		{
			int x=daj(1, 1, n1, i.first, i.second, pas(v));
			if (x==-1)
				break;
			//~ debug() << "z " << v << " do " << pas(x);
			dfs3(x);
		}
	}
}

int tak[nax];

void oznacz(int v)
{
	if (znacz[v])
		return;
	znacz[v]=1;
	
	//~ debug() << "znacze " << v;
	auto wez=get_path(prze[pas(v)].first, prze[pas(v)].second);
	//~ debug() << wez;
	for (auto i : wez)
	{
		if (i.first==pre[wsp[pas(v)]])
			i.first++;
		if (i.second<i.first)
			continue;
		//~ debug() << v << " na " << i;
		while(1)
		{
			int x=daj(1, 1, n1, i.first, i.second, pas(v));
			if (x==-1)
				break;
			//~ debug() << "z " << v << " do " << pas(x);
			oznacz(x);
		}
	}
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	scanf("%d", &m);
	for (int i=1; i<=m; i++)
		for (int j=0; j<2; j++)
		{
			scanf("%d%d", &lubi[i][j].first, &lubi[i][j].second);
			k++;
			numy[i][j]=k;
			prze[k]=lubi[i][j];
		}
	odl[1]=1;
	dfs1(1, 0);
	
	dfs_roz(1);
	dfs_pre(1);
	
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<2; j++)
		{
			auto wez=get_path(lubi[i][j].first, lubi[i][j].second);
			wsp[numy[i][j]]=lca(lubi[i][j].first, lubi[i][j].second);
			for (int l=0; l<(int)wez.size(); l++)
			{
				pii x=wez[l];
				if (x.first==pre[wsp[numy[i][j]]])
					x.first++;
				rzuc(1, 1, n1, x.first, x.second, numy[i][j]);
			}
		}
	}
	
	for (int i=1; i<=k; i++)
		dfs2(i);
	
	//~ debug() << range(mypost+1, mypost+1+k);
	for (int i=1; i<2*n1; i++)
	{
		smie1[i].clear();
		smie2[i].clear();
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<2; j++)
		{
			auto wez=get_path(lubi[i][j].first, lubi[i][j].second);
			//~ wsp[numy[i][j]]=lca(lubi[i][j].first, lubi[i][j].second);
			for (int l=0; l<(int)wez.size(); l++)
			{
				pii x=wez[l];
				if (x.first==pre[wsp[numy[i][j]]])
					x.first++;
				rzuc(1, 1, n1, x.first, x.second, numy[i][j]);
			}
		}
	}
	
	l=0;
	for (int i=k; i; i--)
	{
		if (!spo[mypost[i]])
		{
			l++;
			dfs3(mypost[i]);
		}
	}
	//~ debug() << range(mypost+1, mypost+1+k);
	//~ debug() << range(spo+1, spo+1+k);
	
	for (int i=1; i<=k; i++)
	{
		if (spo[pas(i)]==spo[i])
		{
			printf("NO\n");
			return 0;
		}
	}
	
	for (int i=1; i<2*n1; i++)
	{
		smie1[i].clear();
		smie2[i].clear();
	}
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<2; j++)
		{
			auto wez=get_path(lubi[i][j].first, lubi[i][j].second);
			//~ wsp[numy[i][j]]=lca(lubi[i][j].first, lubi[i][j].second);
			for (int l=0; l<(int)wez.size(); l++)
			{
				pii x=wez[l];
				if (x.first==pre[wsp[numy[i][j]]])
					x.first++;
				rzuc(1, 1, n1, x.first, x.second, numy[i][j]);
			}
		}
	}
	
	printf("YES\n");
	
	
	for (int i=1; i<=k; i++)
	{
		int x=mypost[i];
		//~ debug() << "biore " << x;
		if (!znacz[x])
		{
			tak[x]=1;
			oznacz(pas(x));
		}
	}
	for (int i=1; i<=m; i++)
	{
		if (tak[numy[i][0]])
			printf("1\n");
		else
			printf("2\n");
	}
	
	return 0;
}
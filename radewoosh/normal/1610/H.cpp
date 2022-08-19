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
const int nax=1200*1007;
const int n1=(1<<19);

vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax], czas;
void dfs_roz(int v) {
	roz[v]=1;                        // drz[] ma nie zawiera krawdzi
	for (int &i : drz[v]) {          // do ojca.
		fad[i]=v;                    // Init:
		dfs_roz(i);                  // dfs_roz(root);
		roz[v]+=roz[i];              // dfs_pre(root);
		if (roz[i]>roz[drz[v][0]])   // Uycie get_path(v, u) zwrci
			swap(i, drz[v][0]);      // przedziay odpowiadajce ciece
	}                                // z v do u. Przedziay odpowiadajce
}                                    // ciece z v do lca maj
void dfs_pre(int v)                  // first>=second, za te dla cieki
{                                    // z lca do u maj first<=second.
	if (!jump[v])                    // Przedziay s po kolei.
		jump[v]=v;                   // Lca wystpuje w nich dwa razy,
	pre[v]=(++czas);                 // najpierw jako second,
	if (!drz[v].empty())             // a zaraz potem jako first.
		jump[drz[v][0]]=jump[v];
	for (int i : drz[v])
		dfs_pre(i);
	post[v]=czas;
}
int lca(int v, int u) {
	while(jump[v]!=jump[u]) {
		if (pre[v]<pre[u])
			swap(v, u);
		v=fad[jump[v]];
	}
	return (pre[v]<pre[u] ? v : u);
}
vector < pair <int,int> > path_up(int v, int u) {
	vector < pair <int,int> > ret;
	while(jump[v]!=jump[u]) {
		ret.push_back({pre[jump[v]], pre[v]});
		v=fad[jump[v]];
	}
	ret.push_back({pre[u], pre[v]});
	return ret;
}
vector < pair <int,int> > get_path(int v, int u) {
	int w=lca(v, u);
	auto ret=path_up(v, w);
	auto pom=path_up(u, w);
	for (auto &i : ret)
		swap(i.first, i.second);
	while(!pom.empty()) {
		ret.push_back(pom.back());
		pom.pop_back();
	}
	return ret;
}

int n, m;

pii par[nax];

int ojc[nax];
vi graf[nax];

int wyn;

bool mniej(int a, int b)
{
	return pre[a]<pre[b];
}

vi drzprz[nax];

void narzuc(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		drzprz[v].push_back(w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	narzuc((v<<1), a, (a+b)>>1, graa, grab, w);
	narzuc((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

int juz[nax];
vi chce[nax];

void zabij(int v)
{
	//~ debug() << "zabijam " << v;
	v=pre[v]+n1-1;
	wyn++;
	while(v)
	{
		for (int i : drzprz[v])
			juz[i]=1;
		drzprz[v].clear();
		v>>=1;
	}
}

void dfs1(int v)
{
	for (int i : graf[v])
		dfs1(i);
		
	int tak=0;
	for (int j : chce[v])
		if (!juz[j])
			tak=1;
	if (tak)
		zabij(v);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=2; i<=n; i++)
	{
		scanf("%d", &ojc[i]);
		graf[ojc[i]].push_back(i);
		drz[ojc[i]].push_back(i);
	}
	for (int i=1; i<=m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a>b)
			swap(a, b);
		par[i]={a, b};
		if (ojc[b]==a)
		{
			printf("-1\n");
			return 0;
		}
	}
	dfs_roz(1);
	dfs_pre(1);
	for (int i=1; i<=n; i++)
		sort(graf[i].begin(), graf[i].end(), mniej);
	for (int i=1; i<=m; i++)
	{
		int a=par[i].first;
		int b=par[i].second;
		if (pre[a]<=pre[b] && post[a]>=post[b])
		{
			int r=graf[a].size();
			vi &on=graf[a];
			int bsa=0;
			int bsb=r-1;
			while(bsa<bsb)
			{
				int bss=(bsa+bsb+2)>>1;
				if (pre[on[bss]]<=pre[b])
					bsa=bss;
				else
					bsb=bss-1;
			}
			int mam=on[bsa];
			chce[mam].push_back(i);
			narzuc(1, 1, n1, pre[mam], pre[b]-1, i);
			narzuc(1, 1, n1, post[b]+1, post[mam], i);
		}
		else
		{
			chce[1].push_back(i);
			if (pre[a]>pre[b])
				swap(a, b);
			narzuc(1, 1, n1, 1, pre[a]-1, i);
			narzuc(1, 1, n1, post[a]+1, pre[b]-1, i);
			narzuc(1, 1, n1, post[b]+1, n, i);
		}
	}
	//~ for (int i=1; i<=n; i++)
		//~ debug() << i << " " << chce[i];
	dfs1(1);
	//~ for (int i=n; i; i--)
	//~ {
		//~ int tak=0;
		//~ for (int j : chce[i])
			//~ if (!juz[j])
				//~ tak=1;
		//~ if (tak)
			//~ zabij(i);
	//~ }
	printf("%d\n", wyn);
	return 0;
}
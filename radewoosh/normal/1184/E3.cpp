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
const int inf=1e9;
const int n1=(1<<17);

int gl[nax];
vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax], czas;
void dfs_roz(int v, int oj=0) {
	
	for (int &i : drz[v])
	{
		if (i==oj)
		{
			swap(i, drz[v].back());
			drz[v].pop_back();
			break;
		}
	}
	
	roz[v]=1;                        // drz[] ma nie zawiera krawdzi
	for (int &i : drz[v]) {          // do ojca.
		fad[i]=v;                    // Init:
		gl[i]=gl[v]+1;
		dfs_roz(i, v);                  // dfs_roz(root);
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

int oj[nax];

pii kra[nax];
int kosz[nax];

int wdrz[nax];
int dos[nax];

int wyn[nax];

bool mniej(int a, int b)
{
	return kosz[a]<kosz[b];
}

int fin(int v)
{
	if (v!=oj[v])
		oj[v]=fin(oj[v]);
	return oj[v];
}

void uni(int a, int b)
{
	oj[fin(a)]=fin(b);
}

int drzmax[nax];

void maxi(int v, int w)
{
	v+=n1-1;
	while(v)
	{
		drzmax[v]=max(drzmax[v], w);
		v>>=1;
	}
}

int czytmax(int v, int a, int b, int graa, int grab)
{
	if (a>=graa && b<=grab)
	{
		return drzmax[v];
	}
	if (a>grab || b<graa)
	{
		return 0;
	}
	return max(
		czytmax((v<<1), a, (a+b)>>1, graa, grab),
		czytmax((v<<1)^1, (a+b+2)>>1, b, graa, grab)
	);
}

int sta[nax];

void zbij(int v, int a, int b, int graa, int grab, int w)
{
	if (a>=graa && b<=grab)
	{
		sta[v]=min(sta[v], w);
		return;
	}
	if (a>grab || b<graa)
	{
		return;
	}
	zbij((v<<1), a, (a+b)>>1, graa, grab, w);
	zbij((v<<1)^1, (a+b+2)>>1, b, graa, grab, w);
}

void zgn(int v, int a, int b)
{
	if (a==b)
		return;
	sta[2*v]=min(sta[2*v], sta[v]);
	sta[2*v+1]=min(sta[2*v+1], sta[v]);
	zgn(2*v, a, (a+b)>>1);
	zgn(2*v+1, (a+b+2)>>1, b);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=m; i++)
	{
		scanf("%d%d%d", &kra[i].first, &kra[i].second, &kosz[i]);
		dos[i]=i;
	}
	sort(dos+1, dos+1+m, mniej);
	for (int i=1; i<=n; i++)
		oj[i]=i;
	for (int h=1; h<=m; h++)
	{
		int x=dos[h];
		int a=kra[x].first;
		int b=kra[x].second;
		if (fin(a)==fin(b))
			continue;
		drz[a].push_back(b);
		drz[b].push_back(a);
		uni(a, b);
		//~ debug() << imie(a);
		//~ debug() << imie(b);
		wdrz[x]=1;
	}
	gl[1]=1;
	//~ debug() << "ta";
	dfs_roz(1);
	//~ debug() << "ta";
	dfs_pre(1);
	//~ debug() << "ta";
	for (int i=1; i<=m; i++)
	{
		if (wdrz[i])
		{
			if (gl[kra[i].first]>gl[kra[i].second])
				swap(kra[i].first, kra[i].second);
			maxi(pre[kra[i].second], kosz[i]);
		}
	}
	for (int i=1; i<2*n1; i++)
		sta[i]=inf;
	for (int i=1; i<=m; i++)
	{
		if (wdrz[i])
			continue;
		auto wez=get_path(kra[i].first, kra[i].second);
		int l=pre[lca(kra[i].first, kra[i].second)];
		//~ debug() << i << " " << wez << "  " << l;
		for (pii j : wez)
		{
			//~ debug() << j;
			if (j.second<j.first)
				swap(j.first, j.second);
			if (j.first==l)
				j.first++;
			if (j.second==l)
				j.second--;
			if (j.second<j.first)
				continue;
			//~ debug() << " " << j;
			wyn[i]=max(wyn[i], czytmax(1, 1, n1, j.first, j.second));
			zbij(1, 1, n1, j.first, j.second, kosz[i]);
		}
	}
	zgn(1, 1, n1);
	for (int i=1; i<=m; i++)
		if (wdrz[i])
			wyn[i]=sta[pre[kra[i].second]+n1-1];
	
	
	
	for (int i=1; i<=m; i++)
		printf("%d\n", wyn[i]);
	return 0;
}
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
 
vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax], czas;
int gle[nax];
vi jumppo[nax];
 
void dfs_roz(int v, int oj=0) {
	jumppo[v].push_back(oj);
	while(jumppo[v].back())
	{
		int a=jumppo[v].back();
		int b=min(jumppo[v].size(), jumppo[a].size())-1;
		jumppo[v].push_back(jumppo[a][b]);
	}
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
		gle[i]=gle[v]+1;
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
 
 
int n, m, k;
 
vi graf[nax];
 
int kon[nax][2];
 
ll wyn;
 
int podnies(int v, int ile)
{
	for (int i=0; (1<<i)<=ile; i++)
		if (ile&(1<<i))
			v=jumppo[v][i];
	return v;
}
 
int liczodl(int a, int b)
{
	return gle[a]+gle[b]-2*gle[lca(a, b)];
}
 
vi sta[nax];
vi spo[nax];
ordered_set<pii> setel[nax];
 
int wprze(ordered_set<int> &secik, int a, int b)
{
	return secik.order_of_key(b+1)-secik.order_of_key(a);
}
 
int wprze(ordered_set<pii> &secik, int a, int b)
{
	return secik.order_of_key({b, nax})-secik.order_of_key({a, -nax});
}
 
map <pii, vi> mapka;
 
int dziecko(int ma, int du)
{
	return pre[ma]>=pre[du] && post[ma]<=post[du];
}
 
bool mniej(int a, int b)
{
	return pre[a]<pre[b];
}
 
vi ver;
vi ndrz[nax];
int korz;
 
void skompresuj(vi wek)
{
	sort(wek.begin(), wek.end(), mniej);
	int roz=wek.size();
	for (int i=0; i+1<roz; i++)
		wek.push_back(lca(wek[i], wek[i+1]));
	sort(wek.begin(), wek.end(), mniej);
	wek.resize(unique(wek.begin(), wek.end())-wek.begin());
	ver=wek;
	vi stos;
	for (int i : wek)
	{
		ndrz[i].clear();
		if (stos.empty())
		{
			korz=i;
		}
		else
		{
			while(!dziecko(i, stos.back()))
				stos.pop_back();
			ndrz[stos.back()].push_back(i);
		}
		stos.push_back(i);
	}
}
 
int tmp[nax];
 
int dfs2(int v, int conaj)
{
	int ret=0;
	while(tmp[v])
	{
		if (gle[v]>=conaj)
			wyn-=ret;
		tmp[v]--;
		ret++;
	}
	for (int i : ndrz[v])
	{
		int x=dfs2(i, conaj);
		if (gle[v]>=conaj)
			wyn-=ret*(ll)x;
		ret+=x;
	}
	return ret;
}
 
void liczmale(vi wek, int kt, int conaj)
{
	ll ret=0;
	vi wie;
	for (int i : wek)
		wie.push_back(kon[i][kt]);
	skompresuj(wie);
	for (int i : ver)
		tmp[i]=0;
	for (int i : wie)
		tmp[i]++;
	dfs2(korz, conaj);
}
 
vi tmpwek[nax];
 
ordered_set<pii> tmpset[nax];
 
void dfs3(int v, int koko)
{
	tmpset[v].clear();
	for (int i : tmpwek[v])
	{
		int tutaj=gle[v]-gle[koko];
		int tam=max(0, k-tutaj);
		int d=kon[i][1];
		if (gle[d]-gle[koko]>=tam)
		{
			int gor=podnies(d, gle[d]-gle[koko]-tam);
			wyn+=wprze(tmpset[v], pre[gor], post[gor]);
		}
		tmpset[v].insert({pre[d], i});
	}
	for (int i : ndrz[v])
	{
		dfs3(i, koko);
		if ((int)tmpset[i].size()>(int)tmpset[v].size())
			tmpset[v].swap(tmpset[i]);
		for (pii j : tmpset[i])
		{
			int tutaj=gle[v]-gle[koko];
			int tam=max(0, k-tutaj);
			int d=kon[j.second][1];
			if (gle[d]-gle[koko]>=tam)
			{
				int gor=podnies(d, gle[d]-gle[koko]-tam);
				wyn+=wprze(tmpset[v], pre[gor], post[gor]);
			}
		}
		for (pii j : tmpset[i])
			tmpset[v].insert(j);
	}
}
 
void solve(vi wek, int v, int lew, int pra)
{
	int r=wek.size();
	if (r<=1)
		return;
	for (int i : wek)
		if (pre[kon[i][0]]>pre[kon[i][1]])
			swap(kon[i][0], kon[i][1]);
	liczmale(wek, 0, gle[v]+k);
	liczmale(wek, 1, gle[v]+k);
	
	vi wsz{lew};
	for (int i : wek)
		wsz.push_back(kon[i][0]);
	skompresuj(wsz);
	for (int i : ver)
		tmpwek[i].clear();
	for (int i : wek)
		tmpwek[kon[i][0]].push_back(i);
	dfs3(lew, v);
}
 
void dfs1(int v)
{
	for (int i : sta[v])
		setel[v].insert({pre[v], i});
	for (int i : drz[v])
	{
		dfs1(i);
		if ((int)setel[v].size()<(int)setel[i].size())
			setel[v].swap(setel[i]);
		for (pii j : setel[i])
			setel[v].insert(j);
	}
	mapka.clear();
	for (int i : spo[v])
	{
		int a=kon[i][0];
		int b=kon[i][1];
		setel[v].erase({pre[a], i});
		setel[v].erase({pre[b], i});
		if (gle[a]>=gle[v]+k)
		{
			int lim=podnies(a, gle[a]-gle[v]-k);
			wyn+=wprze(setel[v], pre[lim], post[lim]);
		}
		if (gle[b]>=gle[v]+k)
		{
			int lim=podnies(b, gle[b]-gle[v]-k);
			wyn+=wprze(setel[v], pre[lim], post[lim]);
		}
		if (a==v || b==v)
			continue;
		a=podnies(a, gle[a]-gle[v]-1);
		b=podnies(b, gle[b]-gle[v]-1);
		if (pre[a]>pre[b])
			swap(a, b);
		mapka[{a, b}].push_back(i);
	}
	for (auto i : mapka)
		solve(i.second, v, i.first.first, i.first.second);
}
 
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graf[a].push_back(b);
		graf[b].push_back(a);
		drz[a].push_back(b);
		drz[b].push_back(a);
	}
	gle[1]=1;
	dfs_roz(1);
	dfs_pre(1);
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<2; j++)
			scanf("%d", &kon[i][j]);
		if (liczodl(kon[i][0], kon[i][1])<k)
		{
			i--;
			m--;
		}
	}
	debug() << imie(m);
	for (int i=1; i<=m; i++)
	{
		for (int j=0; j<2; j++)
			sta[kon[i][j]].push_back(i);
		spo[lca(kon[i][0], kon[i][1])].push_back(i);
	}
	dfs1(1);
	
	
	printf("%lld\n", wyn);
	return 0;
}
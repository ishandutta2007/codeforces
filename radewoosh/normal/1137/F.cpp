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

int n, q;
int gle[nax];

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
	{
		gle[i]=gle[v]+1;
		dfs_pre(i);
	}
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


int dys(int a, int b)
{
	return gle[a]+gle[b]-2*gle[lca(a, b)];
}

void dfs1(int v, int oj)
{
	for (int &i : drz[v])
	{
		if (i==oj)
		{
			swap(i, drz[v].back());
			drz[v].pop_back();
			break;
		}
	}
	for (int i : drz[v])
		dfs1(i, v);
}

int pot[nax];

void dodaj(int v, int w)
{
	//~ debug() << "   w " << v << " " << w;
	for (int i=v; i<nax; i+=(i&(-i)))
		pot[i]+=w;
}

int czyt(int v)
{
	int ret=0;
	for (int i=v; i; i-=(i&(-i)))
		ret+=pot[i];
	return ret;
}

int ile[nax];
int kto[nax];

struct prze
{
	int l;
	int p;
	int kol;
	prze(){}
	prze(int ll, int pp, int kolkol)
	{
		l=ll;
		p=pp;
		kol=kolkol;
	}
};

bool operator < (prze a, prze b)
{
	return a.l<b.l;
}

set <prze> setel;

int dfs2(int v)
{
	int ret=v;
	for (int i : drz[v])
		ret=max(ret, dfs2(i));
	ile[ret]++;
	dodaj(ret, 1);
	//~ debug() << v << " to " << ret << "   " << pre[v];
	setel.insert(prze(pre[v], pre[v], ret));
	//~ for (auto i : setel)
		//~ debug() << i.l << " " << i.p << " " << i.kol;
	return ret;
}

char wcz[17];
int gdz;

void tnij(int v)
{
	auto it=setel.upper_bound(prze(v, -1, -1));
	it--;
	if ((*it).l==v)
		return;
	prze x=(*it);
	setel.erase(it);
	setel.insert(prze(x.l, v-1, x.kol));
	setel.insert(prze(v, x.p, x.kol));
}

void maluj(pii v, int czym)
{
	//~ debug() << "przed";
	//~ for (auto i : setel)
		//~ debug() << i.l << " " << i.p << " " << i.kol;
	tnij(v.first);
	tnij(v.second+1);
	//~ debug() << "po " << v;
	//~ for (auto i : setel)
		//~ debug() << i.l << " " << i.p << " " << i.kol;
	//~ debug() << "kon";
	auto it=setel.lower_bound(prze(v.first, -1, -1));
	assert((*it).l==v.first);
	//~ debug() << "nom";
	while(1)
	{
		if ((*it).l>v.second)
			break;
		auto jt=it;
		it++;
		ile[(*jt).kol]-=((*jt).p-(*jt).l+1);
		dodaj((*jt).kol, -((*jt).p-(*jt).l+1));
		setel.erase(jt);
	}
	ile[czym]+=v.second-v.first+1;
	dodaj(czym, v.second-v.first+1);
	setel.insert(prze(v.first, v.second, czym));
}

void up(int v)
{
	auto wez=get_path(gdz, v);
	
	//~ debug() << wez;
	
	int zak=pre[lca(v, gdz)];
	
	int policz=0;
	for (int i=0; i<(int)wez.size(); i++)
	{
		pii x=wez[i];
		if (x.first>x.second)
			swap(x.first, x.second);
		maluj(x, n);
	}
	
	n++;
	maluj({pre[v], pre[v]}, n);
	
	kto[n]=v;
	gdz=v;
}

int policz(int v)
{
	auto it=setel.upper_bound(prze(pre[v], -1, -1));
	it--;
	//~ debug() << (*it).l << " " << (*it).p << " " << (*it).kol;
	auto x=(*it);
	assert(x.l<=pre[v] && x.p>=pre[v]);
	//~ debug() << "nom";
	//~ debug() << czyt(x.kol-1) << " " << dys(v, kto[x.kol]);
	return czyt(x.kol-1)+dys(v, kto[x.kol])+1;
}

void query()
{
	//~ for (auto i : setel)
		//~ debug() << i.l << " " << i.p << " " << i.kol;
	scanf("%s", wcz);
	if (wcz[0]=='u')
	{
		int v;
		scanf("%d", &v);
		up(v);
	}
	if (wcz[0]=='w')
	{
		int x;
		scanf("%d", &x);
		printf("%d\n", policz(x));
	}
	if (wcz[0]=='c')
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (policz(a)<policz(b))
			printf("%d\n", a);
		else
			printf("%d\n", b);
	}
}

int main()
{
	setel.insert(prze(0, 0, 0));
	scanf("%d%d", &n, &q);
	setel.insert(prze(n+1, n+1, 0));
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		drz[a].push_back(b);
		drz[b].push_back(a);
	}
	dfs1(n, 0);
	//~ for (int i=1; i<=n; i++)
		//~ debug() << drz[i];
	dfs_roz(n);
	dfs_pre(n);
	dfs2(n);
	gdz=n;
	for (int i=1; i<=n; i++)
		kto[i]=i;
	//~ debug() << range(pre+1, pre+1+n);
	while(q--)
		query();
	return 0;
}
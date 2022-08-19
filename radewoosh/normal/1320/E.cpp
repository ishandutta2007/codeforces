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

int n;

vector <int> drz[nax];
int roz[nax], jump[nax], pre[nax], post[nax], fad[nax], czas;
int gle[nax];
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

int przo(int v, int u)
{
	return pre[v]<pre[u] && post[v]>=post[u];
}

int k, m;
int sta[nax];
int szy[nax];

int pyt[nax];

int r;
vi wie;

vector <pii> graf[nax];

int kto[nax];

bool mniej(int a, int b)
{
	return pre[a]<pre[b];
}

void edge(int a, int b, int c)
{
	//~ debug() << "krawe " << a << " " << b << " " << c;
	graf[a].push_back({b, c});
	graf[b].push_back({a, c});
}

struct supara
{
	int kto;
	int mia;
	int dro;
	supara()
	{
	}
	supara(int x, int y, int z)
	{
		kto=x;
		mia=y;
		dro=z;
	}
};

int suf(int a, int b)
{
	return (a+b-1)/b;
}

bool operator < (supara x, supara y)
{
	int kx=suf(x.dro, szy[x.kto]);
	int ky=suf(y.dro, szy[y.kto]);
	//~ debug() << x.kto << " vs " << y.kto;
	//~ debug() << imie(kx) << imie(ky);
	if (kx!=ky)
		return kx>ky;
	return x.kto>y.kto;
}

void query()
{
	scanf("%d%d", &k, &m);
	wie.clear();
	wie.push_back(1);
	for (int i=1; i<=k; i++)
	{
		scanf("%d%d", &sta[i], &szy[i]);
		wie.push_back(sta[i]);
	}
	for (int i=1; i<=m; i++)
	{
		scanf("%d", &pyt[i]);
		wie.push_back(pyt[i]);
	}
	sort(wie.begin(), wie.end(), mniej);
	for (int i=(int)wie.size()-1; i>0; i--)
	{
		int a=wie[i];
		int b=wie[i-1];
		if (a==b)
			continue;
		int c=lca(a, b);
		if (c==a || c==b)
			continue;
		wie.push_back(c);
	}
	sort(wie.begin(), wie.end(), mniej);
	wie.resize(unique(wie.begin(), wie.end())-wie.begin());
	//~ debug() << wie;
	r=wie.size();
	for (int i : wie)
		graf[i].clear();
	vi stos;
	for (int i : wie)
	{
		while(!stos.empty() && !przo(stos.back(), i))
			stos.pop_back();
		if (!stos.empty())
			edge(stos.back(), i, gle[i]-gle[stos.back()]);
		stos.push_back(i);
	}
	for (int i : wie)
		kto[i]=0;
	priority_queue <supara> kol;
	for (int i=1; i<=k; i++)
		kol.push(supara(i, sta[i], 0));
	while(!kol.empty())
	{
		supara v=kol.top();
		kol.pop();
		if (kto[v.mia])
			continue;
		//~ debug() << imie(v.kto) << imie(v.mia) << imie(v.dro) << imie(suf(v.dro, szy[v.kto]));
		kto[v.mia]=v.kto;
		for (pii i : graf[v.mia])
			if (!kto[i.first])
				kol.push(supara(v.kto, i.first, v.dro+i.second));
	}
	
	
	
	
	for (int i=1; i<=m; i++)
		printf("%d ", kto[pyt[i]]);
	printf("\n");
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		drz[a].push_back(b);
		drz[b].push_back(a);
	}
	dfs_roz(1);
	dfs_pre(1);
	//~ debug() << range(pre+1, pre+1+n);
	int q;
	scanf("%d", &q);
	while(q--)
		query();
	return 0;
}
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

int n, q;
ll tab[nax];
ll fen[nax];

void pisz(int a, int b, ll w)
{
	for (int i=b; i; i-=(i&(-i)))
		fen[i]+=w;
	for (int i=a-1; i; i-=(i&(-i)))
		fen[i]-=w;
}

ll czyt(int v)
{
	ll ret=0;
	for (int i=v; i<=n; i+=(i&(-i)))
		ret+=fen[i];
	return ret;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i=1; i<=n; i++)
	{
		scanf("%lld", &tab[i]);
		tab[i]=abs(tab[i]);
	}
	for (int i=1; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		drz[a].push_back(b);
		drz[b].push_back(a);
	}
	dfs_roz(1, 0);
	dfs_pre(1);
	for (int i=1; i<=n; i++)
		pisz(pre[i], post[i], tab[i]);
	while(q--)
	{
		int typ;
		scanf("%d", &typ);
		if (typ==1)
		{
			int a;
			ll c;
			scanf("%d%lld", &a, &c);
			c=abs(c);
			pisz(pre[a], post[a], -tab[a]);
			tab[a]=c;
			pisz(pre[a], post[a], tab[a]);
		}
		else
		{
			int a, b;
			scanf("%d%d", &a, &b);
			int w=lca(a, b);
			ll sci=czyt(pre[a])+czyt(pre[b])-2*czyt(pre[w]);
			//~ debug() << sci;
			sci*=2;
			sci+=2*tab[w];
			sci-=tab[a]+tab[b];
			printf("%lld\n", sci);
		}
	}
	return 0;
}
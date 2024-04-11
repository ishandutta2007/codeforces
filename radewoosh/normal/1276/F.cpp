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


struct suffix_automaton {
	vector<map<char,int>> edges;
	vector<int> link, length;
	int last;
	suffix_automaton(string s) {
		edges.push_back(map<char,int>());
		link.push_back(-1);
		length.push_back(0);
		last = 0;
		for (int i=0; i<(int)s.size(); i++) {
			edges.push_back(map<char,int>());
			length.push_back(i+1);
			link.push_back(0);
			int r = edges.size() - 1;
			int p = last;
			while (p >= 0 && !edges[p].count(s[i])) {
				edges[p][s[i]] = r;
				p = link[p];
			}
			if (p != -1) {
				int q = edges[p][s[i]];
				if (length[p] + 1 == length[q]) {
					link[r] = q;
				}
				else {
					edges.push_back(edges[q]);
					length.push_back(length[p] + 1);
					link.push_back(link[q]);
					int qq = edges.size()-1;
					link[q] = link[r] = qq;
					while (p >= 0 && edges[p][s[i]] == q) {
						edges[p][s[i]] = qq;
						p = link[p];
					}
				}
			}
			last = r;
		}
	}
};

suffix_automaton X=suffix_automaton("");
suffix_automaton Y=suffix_automaton("");

int n;
char wcz[nax];

vi drz[nax][2];

int m, k;
ll ma[nax][2];

ll sum[nax];

ll wyn;

set <int> setel[nax];
ll trz[nax];

int roz[nax], jump[nax], pre[nax], post[nax], fad[nax], czas, kt[nax];
void dfs_roz(int v) {
	roz[v]=1;                        // drz[] ma nie zawiera krawdzi
	for (int &i : drz[v][1]) {          // do ojca.
		fad[i]=v;                    // Init:
		dfs_roz(i);                  // dfs_roz(root);
		roz[v]+=roz[i];              // dfs_pre(root);
		if (roz[i]>roz[drz[v][1][0]])   // Uycie get_path(v, u) zwrci
			swap(i, drz[v][1][0]);      // przedziay odpowiadajce ciece
	}                                // z v do u. Przedziay odpowiadajce
}                                    // ciece z v do lca maj
void dfs_pre(int v)                  // first>=second, za te dla cieki
{                                    // z lca do u maj first<=second.
	if (!jump[v])                    // Przedziay s po kolei.
		jump[v]=v;                   // Lca wystpuje w nich dwa razy,
	pre[v]=(++czas);                 // najpierw jako second,
	kt[pre[v]]=v;
	if (!drz[v][1].empty())             // a zaraz potem jako first.
		jump[drz[v][1][0]]=jump[v];
	for (int i : drz[v][1])
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

void dfs1(int v)
{
	sum[v]+=ma[v][1];
	for (int i : drz[v][1])
	{
		sum[i]=sum[v];
		dfs1(i);
	}
	//~ debug() << "dfs1 " << v << "    " << ma[v][1] << " " << sum[v];
}

void dodaj(int v, int x)
{
	//~ debug() << v << " dodaje " << x;
	if (setel[v].count(x))
		return;
	//~ debug() << "siedzi";
	setel[v].insert(x);
	trz[v]+=sum[kt[x]];
	auto it=setel[v].find(x);
	int a=-1;
	if (it!=setel[v].begin())
	{
		it--;
		int y=(*it);
		it++;
		a=y;
		trz[v]-=sum[lca(kt[y], kt[x])];
	}
	it++;
	int b=-1;
	if (it!=setel[v].end())
	{
		int y=(*it);
		b=y;
		trz[v]-=sum[lca(kt[y], kt[x])];
	}
	if (a>0 && b>0)
		trz[v]+=sum[lca(kt[a], kt[b])];
	it--;
}

vi pol[nax];

int ga[nax];
int gb[nax];

void dfs2(int v)
{
	for (int i : pol[v])
		dodaj(v, pre[i]);
	//~ debug() << v << " " << pol[v] << " " << setel[v] << "   " << drz[v][0];
	for (int i : drz[v][0])
	{
		dfs2(i);
		if ((int)setel[i].size()>(int)setel[v].size())
		{
			setel[v].swap(setel[i]);
			swap(trz[v], trz[i]);
		}
		for (int j : setel[i])
			dodaj(v, j);
		setel[i].clear();
	}
	//~ debug() << v << " " << setel[v] << "   " << trz[v] << " " << ma[v][0];
	
	wyn+=trz[v]*ma[v][0];
}

int main()
{
	scanf("%s", wcz+1);
	n=strlen(wcz+1);
	string s="";
	for (int i=1; i<=n; i++)
		s.push_back(wcz[i]);
	X=suffix_automaton(s);
	reverse(s.begin(), s.end());
	Y=suffix_automaton(s);
	reverse(s.begin(), s.end());
	
	m=X.edges.size();
	k=Y.edges.size();
	for (int i=1; i<m; i++)
	{
		drz[X.link[i]][0].push_back(i);
		ma[i][0]=X.length[i]-X.length[X.link[i]];
		//~ debug() << "1 " << i << "  " << X.link[i] << " " << X.length[i];
	}
	for (int i=1; i<k; i++)
	{
		drz[Y.link[i]][1].push_back(i);
		ma[i][1]=Y.length[i]-Y.length[Y.link[i]];
		//~ debug() << "2 " << i << "  " << Y.link[i] << " " << Y.length[i];
	}
	ma[0][0]=ma[0][1]=1;
	for (int i=0; i<m; i++)
		wyn+=ma[i][0];
	//~ debug() << imie(wyn);
	dfs_roz(0);
	dfs_pre(0);
	dfs1(0);
	
	int v=0;
	for (int i=1; i<=n; i++)
	{
		ga[i]=v;
		v=X.edges[v][wcz[i]];
	}
	v=0;
	for (int i=n; i; i--)
	{
		gb[i]=v;
		v=Y.edges[v][wcz[i]];
	}
	for (int i=1; i<=n; i++)
	{
		//~ debug() << i << " " << ga[i] << " " << gb[i];
		pol[ga[i]].push_back(gb[i]);
	}
	dfs2(0);
	
	printf("%lld\n", wyn);
	return 0;
}
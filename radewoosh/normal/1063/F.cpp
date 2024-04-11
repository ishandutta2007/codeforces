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
const int inf=1e9;

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

int n;
char wcz[nax];

int m;
int dlu[nax];
vi graf[nax];
vi drz[nax];
pii prze[nax];

int l;
int pre[nax];
int post[nax];
int kto[nax];

int wyn;

//~ bitset <d> bylo[nax];

void dfs1(int v)
{
	l++;
	pre[v]=l;
	kto[l]=dlu[v];
	for (int i : drz[v])
		dfs1(i);
	post[v]=l;
}

int szuk(int v, int lim)
{
	int ret=-1;
	for (int i=pre[v]; i<=post[v]; i++)
		if (kto[i]>=lim && (ret==-1 || kto[i]<ret))
			ret=kto[i];
	return ret;
}

//~ void dfs2(int v, int res, int w)
//~ {
	//~ debug() << v << " " << res << " " << w << " " << prze[v];
	//~ for (int i=prze[v].first; i<=prze[v].second; i++)
	//~ {
		//~ w=szuk(v, w+i);
		//~ if (w==-1)
			//~ return;
		//~ res++;
		//~ wyn=max(wyn, res);
	//~ }
	//~ debug() << v << " " << res << " " << w << " " << prze[v];
	//~ for (int i : graf[v])
		//~ dfs2(i, res, w);
//~ }

int kied[nax];
int najk[nax];

vi kandy;

int czas;

void cons(int v, int kon)
{
	if (kied[v]!=czas)
	{
		kied[v]=czas;
		kandy.push_back(v);
		najk[v]=inf;
	}
	najk[v]=min(najk[v], kon);
}

int main()
{
	scanf("%d", &n);
	scanf("%s", wcz+1);
	reverse(wcz+1, wcz+n+1);
	string s="";
	for (int i=1; i<=n; i++)
		s.push_back(wcz[i]);
	X=suffix_automaton(s);
	m=X.link.size();
	for (int i=0; i<m; i++)
		dlu[i]=-1;
	int w=0;
	dlu[0]=0;
	for (int i=1; i<=n; i++)
	{
		w=X.edges[w][wcz[i]];
		dlu[w]=i;
		//~ debug() << i << " " << w;
	}
	for (int i=1; i<m; i++)
	{
		prze[i]={X.length[X.link[i]]+1, X.length[i]};
		drz[X.link[i]].push_back(i);
	}
	for (int i=0; i<m; i++)
		for (auto j : X.edges[i])
			graf[i].push_back(j.second);
	dfs1(0);
	vector <pii> trz;
	trz.push_back({0, 0});
	for (int i=0; i<m; i++)
		kied[i]=-1;
	for (int h=0; !trz.empty(); h++)
	{
		wyn=h;
		czas=h;
		kandy.clear();
		
		for (pii i : trz)
		{
			int v=i.first;
			int kon=i.second;
			if (h==prze[v].second)
			{
				for (int j : drz[v])
				{
					int w=szuk(j, kon+1+h);
					if (w!=-1)
						cons(j, w);
				}
			}
			else
			{
				int w=szuk(v, kon+1+h);
				if (w!=-1)
					cons(v, w);
			}
			for (int j : graf[v])
			{
				int w=szuk(j, kon+1+h);
				if (w!=-1)
					cons(j, w);
			}
		}
		
		trz.clear();
		for (int i : kandy)
			trz.push_back({i, najk[i]});
	}
	printf("%d\n", wyn);
	return 0;
}
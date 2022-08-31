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
const int inf=1e9+7;

// Dinic O(n^2 * m) lub O(MaxFlow * (n + m)).
// Dla grafw z krawdziami jednostkowymi dziaa w O(m * sqrt(n)).

using T = long long;

class Flow {
  struct E {
    int dest;
    T orig, *lim, *rev;
  };
  int zr, uj, n = 0;
  vector<unique_ptr<T>> ts;
  vector<vector<E>> graf;
  vector<int> ptr, odl;

  void vert(int v) {
    n = max(n, v + 1);
    graf.resize(n);
    ptr.resize(n);
    odl.resize(n);
  }

  bool iszero(T v) {
    return !v; // Zmieni dla doubli.
  }

  void bfs() {
    fill(odl.begin(), odl.end(), 0);
    vector<int> kol = {zr};
    odl[zr] = 1;
    for (int i = 0; i < (int) kol.size(); i++) {
      for (E& e : graf[kol[i]]) {
        if (!odl[e.dest] and !iszero(*e.lim)) {
          odl[e.dest] = odl[kol[i]] + 1;
          kol.push_back(e.dest);
        }
      }
    }
  }

  T dfs(int v, T lim) {
    if (v == uj) return lim;
    T ret = 0, wez;
    for (int& i = ptr[v]; i < (int) graf[v].size(); i++) {
      E& e = graf[v][i];
      if (odl[e.dest] == odl[v] + 1 and !iszero(*e.lim) and
          !iszero(wez = dfs(e.dest, min(*e.lim, lim)))) {
        ret += wez;
        *e.lim -= wez;
        *e.rev += wez;
        lim -= wez;
        if (iszero(lim)) break;
      }
    }
    return ret;
  }

 public:
  void add_edge(int u, int v, T lim, bool bi = false /* bidirectional? */) {
    vert(max(u, v));
    T *a = new T(lim), *b = new T(lim * bi);
    ts.emplace_back(a);
    ts.emplace_back(b);
    graf[u].push_back(E{v, lim,      a, b});
    graf[v].push_back(E{u, lim * bi, b, a});
  }

  T dinic(int zr_, int uj_) {
    zr = zr_; uj = uj_;
    vert(max(zr, uj));
    T ret = 0;
    while (true) {
      bfs();
      fill(ptr.begin(), ptr.end(), 0);
      const T sta = dfs(zr, numeric_limits<T>::max());  // Dla doubli mona da
      if (iszero(sta)) break;                           // infinity() zamiast
      ret += sta;                                       // max().
    }
    return ret;
  }

  vector<int> cut() {
    vector<int> ret;
    bfs();
    for (int i = 0; i < n; i++)
      if (odl[i])
        ret.push_back(i);
    return ret;
  }

  map<pair<int, int>, T> get_flowing() {  // Tam gdzie plynie 0 moe nie by
    map<pair<int, int>, T> ret;           // krawdzi.
    for (int i = 0; i < n; i++)
      for (E& e : graf[i])
        if (*e.lim < e.orig)
          ret[make_pair(i, e.dest)] += e.orig - *e.lim;
    for (auto& i : ret) {
      const pair<int, int> rev{i.first.second, i.first.first};
      const T x = min(i.second, ret[rev]);
      i.second -= x;
      ret[rev] -= x;
    }
    return ret;
  }
};


int n;
pii tab[nax];

vector <pair<pii,pii> > wyn[3];

map <int,vector<pii> > mapa;

vector <pii> lacz;
int czypio[nax];
int gdz[nax];

Flow janusz;

void rysuj(int a, int b, int typ)
{
	debug() << a << " " << b;
	wyn[typ].push_back({tab[a], tab[b]});
}

int main()
{
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
	{
		scanf("%d%d", &tab[i].first, &tab[i].second);
		mapa[tab[i].first].push_back({tab[i].second, i});
		mapa[tab[i].second+inf].push_back({tab[i].first, i});
	}
	for (auto &i : mapa)
	{
		sort(i.second.begin(), i.second.end());
		for (int j=1; j<(int)i.second.size(); j++)
			lacz.push_back({i.second[j-1].second, i.second[j].second});
	}
	debug() << lacz;
	int m=lacz.size();
	for (int i=0; i<m; i++)
	{
		if (tab[lacz[i].first].first==tab[lacz[i].second].first)
			czypio[i]=1;
	}
	for (int i=0; i<m; i++)
	{
		for (int j=0; j<m; j++)
		{
			if (czypio[i] && !czypio[j])
			{
				if (tab[lacz[i].first].second<tab[lacz[j].first].second && tab[lacz[i].second].second>tab[lacz[j].first].second)
				{
					if (tab[lacz[j].first].first<tab[lacz[i].first].first && tab[lacz[j].second].first>tab[lacz[i].first].first)
					{
						janusz.add_edge(i, j, inf);
					}
				}
			}
		}
	}
	for (int i=0; i<m; i++)
	{
		if (czypio[i])
			janusz.add_edge(m, i, 1);
		else
			janusz.add_edge(i, m+1, 1);
	}
	int x=janusz.dinic(m, m+1);
	debug() << imie(x);
	vi wez=janusz.cut();
	for (int i : wez)
		gdz[i]=1;
	set <pii> ost;
	for (int i=0; i<m; i++)
		if (czypio[i]==gdz[i])
			ost.insert(lacz[i]);
	debug() << ost;
	
	for (auto i : mapa)
	{
		int pam=i.second[0].second;
		for (int j=0; j<(int)i.second.size(); j++)
		{
			if (j+1==(int)i.second.size() || !ost.count({i.second[j].second, i.second[j+1].second}))
			{
				rysuj(pam, i.second[j].second, i.first<=inf);
				if (j+1!=(int)i.second.size())
					pam=i.second[j+1].second;
			}
		}
	}
	
	for (int h=0; h<2; h++)
	{
		printf("%d\n", (int)wyn[h].size());
		for (auto i : wyn[h])
			printf("%d %d %d %d\n", i.first.first, i.first.second, i.second.first, i.second.second);
	}
	return 0;
}
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
const int inf=1e9;
const int d=25;

using T = int;
struct E {
int dest;
T orig, *lim, *rev;
int id;
};
struct Flow {
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
  vector<pair<T*,int>> zmiany;
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
        zmiany.push_back({e.lim, wez});
        zmiany.push_back({e.rev, -wez});
        if (iszero(lim)) break;
      }
    }
    return ret;
  }
  void add_edge(int u, int v, T lim, int id, bool bi = false /* bidirectional? */) {
    vert(max(u, v));
    T *a = new T(lim), *b = new T(lim * bi);
    ts.emplace_back(a);
    ts.emplace_back(b);
    graf[u].push_back(E{v, lim,      a, b, id});
    graf[v].push_back(E{u, lim * bi, b, a, -1});
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
  int rollback(int v)
  {
	  while((int)zmiany.size()>v)
	  {
		  auto wez=zmiany.back();
		  zmiany.pop_back();
		  (*wez.first)+=wez.second;
	  }
  }
  void zwieksz(E* kra, int ile)
  {
	  (*(kra->lim))+=ile;
	  zmiany.push_back({kra->lim, -ile});
  }
};



int n, m, k, q;

pii kra[nax];
int wag[nax];

E* wsk[nax];

Flow janusz;

int tutaj[nax];

int wary[nax];
int suma[nax];

void rek(int v, int mas, int cal)
{
	if (v==k)
	{
		tutaj[mas]=cal;
		return;
	}
	rek(v+1, mas, cal);
	int stan=janusz.zmiany.size();
	janusz.zwieksz(wsk[v], d);
	int wez=janusz.dinic(1, n);
	rek(v+1, mas|(1<<v), cal+wez);
	janusz.rollback(stan);
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &q);
	for (int i=0; i<m; i++)
	{
		scanf("%d%d%d", &kra[i].first, &kra[i].second, &wag[i]);
		janusz.add_edge(kra[i].first, kra[i].second, wag[i], i);
	}
	for (int i=0; i<janusz.n; i++)
	{
		for (int j=0; j<(int)janusz.graf[i].size(); j++)
		{
			if (janusz.graf[i][j].id>=0)
				wsk[janusz.graf[i][j].id]=(&janusz.graf[i][j]);
		}
	}
	int wez=janusz.dinic(1, n);
	rek(0, 0, wez);
	//~ debug() << range(tutaj, tutaj+(1<<k));
	while(q--)
	{
		int wyn=inf;
		for (int i=0; i<k; i++)
			scanf("%d", &wary[i]);
		for (int i=1; i<(1<<k); i++)
		{
			int x=__builtin_ctz(i);
			suma[i]=suma[i^(1<<x)]+wary[x];
		}
		for (int i=0; i<(1<<k); i++)
		{
			wyn=min(wyn, tutaj[i]+suma[((1<<k)-1)^i]);
		}
		printf("%d\n", wyn);
	}
	return 0;
}
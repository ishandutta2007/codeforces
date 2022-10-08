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

using T=int;
struct Flow {
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

struct GomoryHu {
  vector<vector< pair<int,int> >> graph, tree;
  vector<vector<int>> nodes;
  vector<bool> visited;
  vector<int> groupId, contrId;
  int wnode, n;
  GomoryHu(int N) : graph(N), visited(N), groupId(N), contrId(N), tree(N), n(N) {}
  
  void addEdge(int u, int v, int cap) {
    graph[u].emplace_back(v, cap);
    graph[v].emplace_back(u, cap);
  }
  void dfs(int v, int type) {
    visited[v] = true; contrId[v] = type;
    for (auto P : tree[v]) { if (!visited[P.first]) { dfs(P.first, type); } }
  }

  vector <pair<pair<int,int>,int>> run() {
    vector<int> allNodes(n);
    iota(allNodes.begin(), allNodes.end(), 0);
    nodes = vector<vector<int>>{allNodes};
    tree = vector<vector<pair<int,int>>>(n);
    fill(groupId.begin(), groupId.end(), 0);

    for (int step = 1; step < n; step++) {
      Flow flow;
      for (int i = 0; i < (int)nodes.size(); i++) {
        if ((int)nodes[i].size() > 1) { wnode = i; break; }
      }
      fill(visited.begin(), visited.end(), false);

      visited[wnode] = true;
      for (auto P : tree[wnode]) { dfs(P.first, nodes[P.first][0]); }
      for (int v = 0; v < n; v++) {
        int a = groupId[v] == wnode ? v : contrId[groupId[v]];
        for (auto& P : graph[v]) {
          int b = groupId[P.first] == wnode ? P.first : contrId[groupId[P.first]];
          if (a != b) { flow.add_edge(a, b, P.second); }
        }
      }

      int a = nodes[wnode][0], b = nodes[wnode][1], f = flow.dinic(a, b);
      auto pom = flow.cut();
      vector <bool> cut(n, false);
      for (int i : pom)
        cut[i]=1;

      for (int v = 0; v < step; v++) {
        if (v == wnode) { continue; }
        for (auto& P : tree[v]) {
          if (P.first == wnode && !cut[contrId[v]]) { P.first = step; }
        }
      }
      vector<pair<int,int>> PA, PB;
      for (auto& P : tree[wnode]) { (cut[contrId[P.first]] ? PA : PB).push_back(P); }
      tree[wnode] = PA; tree[step] = PB;
      tree[wnode].emplace_back(step, f);
      tree[step].emplace_back(wnode, f);
      vector<int> A, B;
      for (int v : nodes[wnode]) {
        (cut[v] ? A : B).push_back(v);
        if (!cut[v]) { groupId[v] = step; }
      }
      nodes[wnode] = A;
      nodes.push_back(B);
    }

    vector <pair<pair<int,int>,int>> res;
    for (int i = 0; i < n; i++)
      for (auto P : tree[i])
        if (nodes[i][0]<nodes[P.first][0])
          res.push_back({{nodes[i][0], nodes[P.first][0]}, P.second});
    return res;
  }
};

int n, m;

vector <pii> graf[nax];

int czas;
int ter[nax];

vi zbi;

void dfs(int v, int oj)
{
	if (ter[v]!=czas)
		return;
	zbi.push_back(v);
	for (pii i : graf[v])
		if (i.first!=oj)
			dfs(i.first, v);
}

void rek(vi wek)
{
	if ((int)wek.size()==1)
	{
		printf("%d ", wek[0]);
		return;
	}
	czas++;
	for (int i : wek)
		ter[i]=czas;
	int mini=1e9;
	pii x;
	for (int i : wek)
		for (pii j : graf[i])
			if (ter[j.first]==czas && j.second<mini)
				mini=j.second, x={i, j.first};
	zbi.clear();
	dfs(x.first, x.second);
	vi a=zbi;
	zbi.clear();
	dfs(x.second, x.first);
	vi b=zbi;
	rek(a);
	rek(b);
}

int main()
{
	scanf("%d%d", &n, &m);
	GomoryHu penis=GomoryHu(n);
	for (int i=0; i<m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		penis.addEdge(a-1, b-1, c);
	}
	auto wez=penis.run();
	ll wyn=0;
	for (auto &i : wez)
	{
		i.first.first++;
		i.first.second++;
		graf[i.first.first].push_back({i.first.second, i.second});
		graf[i.first.second].push_back({i.first.first, i.second});
		wyn+=i.second;
	}
	vi wek(n);
	iota(wek.begin(), wek.end(), 1);
	printf("%lld\n", wyn);
	rek(wek);
	printf("\n");
	return 0;
}
#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

using Weight = i64;
struct Edge{
  int src, dest; Weight weight;
  bool operator < (const Edge &rhs) const {return weight < rhs.weight;}
};

using Edges = vector<Edge>;
using Graph = vector<Edges>;

// Kruskal
// N, operator <
Edges kruskal(int V, Edges &es, UnionFind& uf) {
  Edges res;
  rep(i, es.size()) {
    Edge e = es[i];
    if(uf.root(e.src) != uf.root(e.dest)) {
      uf.merge(e.src, e.dest);
      res.push_back(e);
    }
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i64 n,m;
  cin>>n>>m;
  i64 rem = n * (n-1) / 2 - m;
  //UnionFind uf(n);
  Edges ve;
  i64 xw = 0;
  rep(i,m) {
    i32 u,v;
    i64 w;
    cin>>u>>v>>w;
    xw ^= w;
    --u;--v;
    ve.push_back({u,v,w});
    //uf.merge(u,v);
  }
  sort(ve.begin(), ve.end());
  constexpr i64 INF = 1'000'000'000'000'000'000;
  if (rem < n) {
    vector mat(n, vector(n, false));
    for (auto&& e : ve) {
      mat[e.src][e.dest] = true;
      mat[e.dest][e.src] = true;
    }
    Edges zve;
    rep(i,n)rep(j,i) {
      if (!mat[i][j]) {
        zve.push_back({i,j,0});
      }
    }
    i64 ans = INF;
    rep(i,rem) {
      Edges tmp;
      rep(j,rem) {
        if (i==j) continue;
        tmp.push_back(zve[j]);
      }
      tmp.insert(end(tmp), all(ve));
      Edge xe = {zve[i].src,zve[i].dest,xw};
      auto itr = lower_bound(all(tmp), xe);
      tmp.insert(itr, xe);
      UnionFind uf(n);
      auto mst = kruskal(n, tmp, uf);
      i64 score = 0;
      for (auto&& e : mst) {
        score += e.weight;
      }
      ans = min(ans, score);
    }
    cout<<ans<<endl;
  } else {
    //set<i32> sr;
    //rep(i,n) sr.insert(uf.root(i));
    //if (size(sr) > 1) {
    //  cout<<0<<endl;
    //} else {
    //}
    Graph g(n);
    for (auto&& e : ve) {
      i32 u = e.src;
      i32 v = e.dest;
      i64 w = e.weight;
      g[u].push_back(e);
      g[v].push_back({v,u,w});
    }
    vector<pair<i32,i32>> v(n);
    rep(i,n) {
      v[i] = make_pair(size(g[i]), i);
    }
    auto [sz, idx] = *min_element(all(v));
    vector<bool> ex(n, false);
    for (auto&& e : g[idx]) {
      ex[e.dest] = true;
    }
    UnionFind uf(n);
    vi32 vrem;
    rep(i,n) {
      if (!ex[i]) {
        uf.merge(idx,i);
      } else {
        vrem.push_back(i);
      }
    }
    i32 rsz = size(vrem);
    vector mat(rsz, vector(rsz, false));
    for(auto&&e : ve) {
      i32 u = e.src;
      i32 v = e.dest;
      auto iu = lower_bound(all(vrem), u) - begin(vrem);
      auto iv = lower_bound(all(vrem), v) - begin(vrem);
      if (iu >= rsz || iv >= rsz || vrem[iu] != u || vrem[iv] != v) continue;
      mat[iu][iv] = true;
      mat[iv][iu] = true;
    }
    Edges tmp;
    rep(i,rsz)rep(j,i) {
      if (!mat[i][j]) {
        tmp.push_back({vrem[i],vrem[j],0});
      }
    }
    tmp.insert(end(tmp), all(ve));
    auto mst = kruskal(n, tmp, uf);
    i64 score = 0;
    for (auto&& e : mst) {
      score += e.weight;
    }
    cout<<score<<endl;
  }
  return 0;
}
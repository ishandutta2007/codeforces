#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr int INF = 1e9;

struct UnionFindPP {
  int now;
  vector<pair<int,int>> parent;
  vector<vector<tuple<int,int,int>>> size_his;
  UnionFindPP (int n) : now(0), parent(n, make_pair(INF, -1)), size_his(n, vector(1, make_tuple(0, 1, -1))) {}
  int root(int x, int t) { return t < parent[x].first ? x : root(parent[x].second, t); }
  int size(int x, int t) {
    x = root(x, t);
    auto itr = prev(upper_bound(begin(size_his[x]), end(size_his[x]), make_tuple(t, INF, INF)));
    return get<1>(*itr);
  }
  bool merge(int x, int y) {
    ++now;
    x = root(x, now); y = root(y, now);
    if (x == y) return false;
    int size_x = get<1>(size_his[x].back());
    int size_y = get<1>(size_his[y].back());
    if (size_y > size_x) {
      swap(x, y);
      swap(size_x, size_y);
    }
    size_his[x].emplace_back(now, size_x+size_y, y);
    parent[y] = make_pair(now, x);
    return true;
  }
  template <typename F>
  void walk_all(int x, F func) {
    func(x);
    for (auto&& [t, _, child] : size_his[x]) {
      if (t == 0) continue;
      walk_all(child, func);
    }
  }
};

struct Edge {
  int src,dest;
};

using Graph = vector<vector<Edge>>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m,q;
  cin>>n>>m>>q;
  vecint p(n);
  REP(i,n) cin>>p[i];
  vector<Edge> ve;
  REP(i,m) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    ve.push_back({a,b});
  }
  vector<tuple<int,int>> vq;
  const int INF = 1e8;
  vecint deleted(m,INF);
  REP(i,q) {
    int t,u;
    cin>>t>>u;
    --u;
    vq.emplace_back(t,u);
    if (t == 2) deleted[u] = i;
  }
  UnionFindPP ufpp(n);
  REP(i,m) {
    auto [a, b] = ve[i];
    if (deleted[i] == INF) {
      ufpp.merge(a,b);
    }
  }
  deque<int> vtime;
  vtime.push_back(ufpp.now);
  REP(ri,q) {
    int i = q - ri - 1;
    auto [t,u] = vq[i];
    if (t == 2) {
      auto [a, b] = ve[u];
      ufpp.merge(a, b);
    }
    vtime.push_front(ufpp.now);
  }
  map<int,priority_queue<pair<int,int>>> s;
  REP(i,n) {
    s[ufpp.root(i, ufpp.now)].emplace(p[i], i);
  }
  REP(i,q) {
    auto [t,u] = vq[i];
    if (t == 1) {
      int root = ufpp.root(u, vtime[i]);
      auto& r_s = s[root];
      while (true) {
        auto [val, idx] = r_s.top();
        if (ufpp.root(idx, vtime[i]) == root) break;
        r_s.pop();
      }
      auto [val, idx] = r_s.top();
      cout << val << "\n";
      if (val > 0) {
        r_s.pop();
        r_s.emplace(0, idx);
        p[idx] = 0;
      }
    } else {
      auto [a, b] = ve[u];
      a = ufpp.root(a, vtime[i+1]);
      b = ufpp.root(b, vtime[i+1]);
      if (a == b) continue;
      int r = ufpp.root(a, vtime[i]);
      if (r == b) {
        swap(a, b);
      }
      vector<pair<int,int>> new_b_s;
      ufpp.walk_all(b, [&] (int idx) {
        new_b_s.emplace_back(p[idx], idx);
      });
      s[b] = priority_queue(ALL(new_b_s));
    }
  }
  return 0;
}
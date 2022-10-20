#include <bits/stdc++.h>

using namespace std;

struct DSU {
  int numComp;
  vector<int> root;
  vector<int> sz;

  DSU(int n = 0) : numComp(n), root(n + 1, 0), sz(n + 1, 1) {}

  int getRoot(int u) {
    return root[u] ? root[u] = getRoot(root[u]) : u;
  }

  bool unite(int u, int v) {
    u = getRoot(u); v = getRoot(v);
    if (u == v) return 0;
    sz[v] += sz[u];
    root[u] = v;
    numComp--;
    return 1;
  }
};

struct Point {
  int x, y, a;

  Point operator-(const Point &o) const {
    return {x - o.x, y - o.y};
  }

  bool operator<(const Point &o) const {
    if (x != o.x) return x < o.x;
    return y < o.y;
  }

  long long operator%(const Point &o) const {
    return 1ll * x * o.y - 1ll * y * o.x;
  }
};

const int N = 2010;

int n;
Point p[N];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<int> order;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y >> p[i].a;
    if (i != p[i].a) {
      order.push_back(i);
    }
  }
  if (order.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  sort(order.begin(), order.end(), [&](int u, int v) { return p[u] < p[v]; });
  auto pivot = order[0];
  sort(order.begin() + 1, order.end(), [&](int u, int v) { return (p[u] - p[pivot]) % (p[v] - p[pivot]) > 0ll; });

  DSU dsu(n);
  for (auto u : order) {
    dsu.unite(u, p[u].a);
  }

  vector<pair<int, int>> res;
  for (int i = 1; i + 1 < (int)order.size(); i++) {
    if (dsu.unite(order[i], order[i + 1])) {
      swap(p[order[i]].a, p[order[i + 1]].a);
      res.push_back({order[i], order[i + 1]});
    }
  }
  while (p[pivot].a != pivot) {
    res.push_back({pivot, p[pivot].a});
    swap(p[pivot].a, p[p[pivot].a].a);
  }
  cout << res.size() << '\n';
  for (const auto &u : res) cout << u.first << ' ' << u.second << '\n';
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

// 1-indexed
struct DSU {
  int num_comp;
  vector<int> sz;

  DSU(int n = 0) : num_comp(n), root(n + 1, 0), sz(n + 1, 1) {}

  bool Unite(int u, int v) {
    u = GetRoot(u); v = GetRoot(v);
    if (u == v) return 0;
    sz[v] += sz[u];
    root[u] = v;
    num_comp--;
    return 1;
  }

  int GetRoot(int u) {
    return root[u] ? root[u] = GetRoot(root[u]) : u;
  }

 private:
  vector<int> root;
};

const int N = 1000010;

int n, q;
int a[N];
int p[N];
vector<int> ls[N];
int res[N];
vector<pair<int, int>> queries[N];
bool has[2][N];
vector<int> divs_in_dsu[2][N];
int belong[N];

vector<int> GetDivs(int u) {
  vector<int> res;
  while (u > 1) {
    int x = p[u];
    res.push_back(x);
    while (u % x == 0) {
      u /= x;
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  for (int i = 2; i < N; i++) {
    if (!p[i]) {
      for (int j = i; j < N; j += i) {
        if (!p[j]) p[j] = i;
      }
    }
  }

  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    auto divs = GetDivs(a[i]);
    for (auto div : divs) {
      ls[div].push_back(i);
    }
  }

  DSU dsu(n);

  for (int i = 2; i < N; i++) {
    if (p[i] != i) continue;
    for (int j = 1; j < ls[i].size(); j++) {
      dsu.Unite(ls[i][0], ls[i][j]);
    }
  }

  for (int i = 1; i <= q; i++) {
    int s, t;
    cin >> s >> t;
    res[i] = 2;
    s = dsu.GetRoot(s);
    t = dsu.GetRoot(t);
    if (s == t) {
      res[i] = 0;
      continue;
    }
    if (dsu.sz[s] < dsu.sz[t]) swap(s, t);
    else if (dsu.sz[s] == dsu.sz[t] && s < t) swap(s, t);
    queries[s].push_back({t, i});
  }
  vector<int> roots;
  for (int i = 1; i <= n; i++) {
    if (i == dsu.GetRoot(i)) {
      roots.push_back(i);
    }
  }
  sort(roots.begin(), roots.end(), [&](int u, int v) {
    if (dsu.sz[u] != dsu.sz[v]) return dsu.sz[u] > dsu.sz[v];
    return u > v;
  });

  for (int i = 1; i <= n; i++) {
    int u = dsu.GetRoot(i);
    auto divs = GetDivs(a[i]);
    for (auto div : divs) {
      divs_in_dsu[0][u].push_back(div);
    }
   divs = GetDivs(a[i] + 1);
    for (auto div : divs) {
      divs_in_dsu[1][u].push_back(div);
    }
  }

  auto Normalize = [](vector<int> &a) {
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
  };

  for (auto u : roots) {
    for (int i = 0; i < 2; i++) {
      Normalize(divs_in_dsu[i][u]);
    }
    for (auto div : divs_in_dsu[0][u]) {
      belong[div] = u;
    }
  }

  set<pair<int, int>> good;
  for (int i = 1; i <= n; i++) {
    auto divs = GetDivs(a[i] + 1);
    Normalize(divs);
    vector<int> good_roots;
    for (auto div : divs) {
      if (belong[div]) good_roots.push_back(belong[div]);
    }
    Normalize(good_roots);
    for (int i = 0; i < good_roots.size(); i++) {
      for (int j = i + 1; j < good_roots.size(); j++) {
        int u = good_roots[i];
        int v = good_roots[j];
        good.insert({u, v});
        good.insert({v, u});
      }
    }
  }

  auto Update = [&](int u, bool flag) {
    for (int i = 0; i < 2; i++) {
      for (auto div : divs_in_dsu[i][u]) {
        has[i][div] = flag;
      }
    }
  };

  auto Check = [&](int u) {
    for (int i = 0; i < 2; i++) {
      for (auto div : divs_in_dsu[i][u]) {
        if (has[i ^ 1][div]) return true;
      }
    }
    return false;
  };

  for (auto root : roots) {
    Update(root, true);

    sort(queries[root].begin(), queries[root].end());
    int last = -1;
    int last_res = -1;
    for (auto [u, id] : queries[root]) {
      if (u == last) {
        res[id] = last_res;
        continue;
      }
      int now = 2;
      if (Check(u)) now = 1;

      if (good.count({root, u})) now = 1;
      res[id] = min(res[id], now);
      last = u;
      last_res = now;
    }

    Update(root, false);
  }

  for (int i = 1; i <= q; i++) {
    cout << res[i] << '\n';
  }
  return 0;
}
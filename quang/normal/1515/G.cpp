#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 200010;

int n, m;
vector<pair<int, int>> adj[N];
int num[N], low[N], dead[N];
int cnt_tarjan;
vector<int> stack_tarjan;
int root[N];
vector<int> ls[N];
int t_min[N];
bool used[N];

void Dfs(int u) {
  num[u] = low[u] = ++cnt_tarjan;
  stack_tarjan.push_back(u);
  for (auto [v, w] : adj[u]) {
    if (dead[v]) continue;
    if (!num[v]) Dfs(v);
    low[u] = min(low[u], low[v]);
  }
  if (low[u] == num[u]) {
    while (1) {
      int v = stack_tarjan.back();
      stack_tarjan.pop_back();
      dead[v] = 1;
      root[v] = u;
      ls[u].push_back(v);
      if (u == v) break;
    }
  }
}

int d[N];

void Go(int u, int dist) {
  used[u] = 1;
  d[u] = dist;
  for (auto [v, w] : adj[u]) {
    if (!used[v]) Go(v, dist + w);
  }
}

void Solve(int r) {
  for (auto u : ls[r]) {
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      if (root[v] != r) {
        swap(adj[u][i], adj[u].back());
        adj[u].pop_back();
        i--;
      }
    }
  }

  Go(r, 0);
  t_min[r] = 0;
  for (auto u : ls[r]) {
    for (auto [v, w] : adj[u]) {
      t_min[r] = __gcd(t_min[r], abs(d[u] + w - d[v]));
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, l;
    cin >> u >> v >> l;
    adj[u].push_back({v, l});
  }
  for (int i = 1; i <= n; i++) {
    if (!dead[i]) {
      Dfs(i);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (root[i] == i) Solve(i);
  }

  // for (int i = 1; i <= n; i++) {
  //   if (root[i] == i) {
  //     cout << "# " << i << ' ' << t_min[i] << endl;
  //   }
  // }
  int q;
  cin >> q;
  while (q--) {
    int v, s, t;
    cin >> v >> s >> t;
    if (s == 0) {
      cout << "YES\n";
      continue;
    }
    int r = root[v];
    if (ls[r].size() == 1) {
      cout << "NO\n";
      continue;
    }
    int g = __gcd(t_min[r], t);
    if (s % g == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
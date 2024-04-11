#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<lint> p(n), h(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> h[i];
    }
    for (int i = 0; i + 1 < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
    }

    vector<lint> sum(n);
    vector<lint> happy(n);
    vector<lint> sad(n);
    int can = 1;
    function<void(int, int)> DfsSum = [&](int u, int par) {
      sum[u] = p[u];
      for (auto v : adj[u]) if (v != par) {
        DfsSum(v, u);
        sum[u] += sum[v];
      }
      if ((sum[u] + h[u]) & 1) {
        can = 0;
      }
      happy[u] = (sum[u] + h[u]) / 2;
      sad[u] = (sum[u] - h[u]) / 2;
      if (happy[u] < 0 || sad[u] < 0) {
        can = 0;
      }
    };
    function<lint(int, int)> DfsSolve = [&](int u, int par) {
      lint res = 0;
      for (auto v : adj[u]) if (v != par) {
        int s = DfsSolve(v, u);
        res += s;
      }
      res += p[u];
      if (sad[u] > res) {
        can = 0;
      }
      return sad[u];
    };
    DfsSum(0, -1);
    DfsSolve(0, -1);
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
    if (i == 0) {
      i = -1;
    }
  }

  vector<vector<int>> adj(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  vector<int> down(n), ans(n);

  function<void(int, int)> dfs = [&](int n, int p) {
    down[n] = a[n];
    for (auto &i : adj[n]) if (i != p) {
      dfs(i, n);
      if (down[i] > 0) {
        down[n] += down[i];
      }
    }
  };

  function<void(int, int)> reroot = [&](int n, int p) {
    ans[n] = down[n];
    for (auto &i : adj[n]) if (i != p) {
      if (down[i] > 0) down[n] -= down[i];
      if (down[n] > 0) down[i] += down[n];
      reroot(i, n);
      if (down[n] > 0) down[i] -= down[n];
      if (down[i] > 0) down[n] += down[i];
    }
  };

  dfs(0, -1);
  reroot(0, -1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n - 1];
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 200005;

int n, q;
vector<int> adj[MAXN];
int par[20][MAXN];
int depth[MAXN];

void dfs(int n, int p) {
  par[0][n] = p;
  depth[n] = depth[p] + 1;
  for (auto &i : adj[n]) if (i != p) dfs(i, n);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  dfs(1, 0);
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      par[j][i] = par[j - 1][par[j - 1][i]];
    }
  }

  auto IsAncestor = [&](int a, int b) { // is a an ancestor of b
    int diff = depth[b] - depth[a];
    for (int j = 0; j < 20; j++) {
      if (diff & (1 << j)) {
        b = par[j][b];
      }
    }
    return a == b;
  };

  while (q--) {
    int k;
    cin >> k;
    vector<int> v;
    while (k--) {
      int a;
      cin >> a;
      v.emplace_back(par[0][a]);
    }
    sort(begin(v), end(v), [&](int a, int b) {
      return depth[a] < depth[b];
    });
    int ok = 1;
    for (int i = 0; i + 1 < v.size(); i++) {
      if (!IsAncestor(v[i], v[i + 1])) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}
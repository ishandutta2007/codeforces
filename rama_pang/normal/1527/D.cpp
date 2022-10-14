#include <bits/stdc++.h>
using namespace std;

void Main() {
  int N;
  cin >> N;

  vector<vector<int>> adj(N);
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
  }

  int timer = 0;
  vector<int> st(N);
  vector<int> et(N);
  vector<int> siz(N);
  vector<int> color(N, -1);

  const auto Dfs = [&](const auto &self, int u, int p) -> void {
    st[u] = timer++;
    siz[u] = 1;
    for (auto v : adj[u]) if (v != p) {
      if (p == -1) {
        color[v] = v;
      } else {
        color[v] = color[u];
      }
      self(self, v, u);
      siz[u] += siz[v];
    };
    et[u] = timer - 1;
  };

  const auto IsAncestor = [&](int x, int y) { // Is x ancestor of y?
    return st[x] <= st[y] && et[y] <= et[x];
  };

  Dfs(Dfs, 0, -1);

  vector<long long> ans(N + 1);
  ans[0] = 1ll * N * (N - 1) / 2;
  ans[1] = 1ll * N * (N - 1) / 2;
  for (auto v : adj[0]) {
    ans[1] -= 1ll * siz[v] * (siz[v] - 1) / 2;
  }

  pair<int, int> path = {1, 0};
  for (int mex = 2; mex <= N; mex++) {
    if (color[path.first] != -1 && color[path.second] != -1 && color[path.first] == color[path.second]) {
      break;
    }

    int fi = 0, se = 0;
    if (color[path.first] != -1 && color[path.second] == -1) {
      fi = siz[path.first];
      se = siz[path.second] - siz[color[path.first]];
    } else if (color[path.first] == -1 && color[path.second] != -1) {
      fi = siz[path.first] - siz[color[path.second]];
      se = siz[path.second];
    } else if (color[path.first] != -1 && color[path.second] != -1) {
      fi = siz[path.first];
      se = siz[path.second];
    }
    ans[mex] = 1ll * fi * se;

    if (mex == N) break;
    int u = mex;
    // try to extend path

    // Check if u is already in path
    if (IsAncestor(u, path.first) || IsAncestor(u, path.second)) {
      continue;
    }

    if (IsAncestor(path.first, u)) {
      path.first = u;
      continue;
    }

    if (IsAncestor(path.second, u)) {
      path.second = u;
      continue;
    }

    // path can't be extended
    break;
  }

  for (int i = 0; i < N; i++) {
    ans[i] -= ans[i + 1];
  }
  for (int i = 0; i <= N; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
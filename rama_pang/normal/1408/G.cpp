#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;
  
  vector<vector<int>> A(N, vector<int>(N));
  vector<array<int, 3>> edge;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
      if (i < j) {
        edge.push_back({A[i][j], i, j});
      }
    }
  }
  sort(begin(edge), end(edge));

  vector<vector<int>> dp(N, vector<int>(2));
  for (int i = 0; i < N; i++) {
    dp[i][0] = 0;
    dp[i][1] = 1;
  }

  vector<int> sz(N, 1);
  vector<int> deg(N, 0);

  vector<int> p(N);
  iota(begin(p), end(p), 0);
  function<int(int)> Find = [&](int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  };

  const int MOD = 998244353;
  const auto add = [&](int &a, int b) {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
  };

  for (const auto &ed : edge) {
    int u = Find(ed[1]), v = Find(ed[2]);
    deg[u]++, deg[v]++;

    if (u != v) {
      vector<int> ndp(sz[u] + sz[v] + 1, 0);
      for (int i = 0; i <= sz[u]; i++) {
        for (int j = 0; j <= sz[v]; j++) {
          add(ndp[i + j], 1ll * dp[u][i] * dp[v][j] % MOD);
        }
      }
      dp[u] = ndp;
      sz[u] += sz[v];
      deg[u] += deg[v];
      p[v] = u;
    }

    if (deg[u] == sz[u] * (sz[u] - 1)) {
      add(dp[u][1], 1);
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << dp[Find(0)][i] << " \n"[i == N];
  }
  return 0;
}
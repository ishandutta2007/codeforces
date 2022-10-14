#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<int> p(N);
  vector<int> sz(N, 1);
  iota(begin(p), end(p), 0);
  function<int(int)> Find = [&](int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  };

  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u == 0 || v == 0) {
      continue;
    }
    u = Find(u);
    v = Find(v);
    if (u != v) {
      p[u] = v;
      sz[v] += sz[u];
    }
  }

  vector<int> group;
  for (int i = 1; i < N; i++) {
    if (Find(i) == i) {
      group.emplace_back(sz[i] + 1);
    }
  }


  vector<int> cnt(N + 1);
  for (auto g : group) {
    cnt[g]++;
  }

  const int MOD = 1e9 + 7;
  const auto Radd = [&](int &a, int b) {
    a += b;
    if (a >= MOD) {
      a -= MOD;
    }
  };

  int ans = 0;
  for (int last = 0; last <= N; last++) if (last == 0 || cnt[last] > 0) {
    vector<int> A = group;
    for (int i = 0; i < (int) A.size(); i++) {
      if (A[i] == last) {
        swap(A[i], A.back());
        break;
      }
    }
    if (last != 0) {
      A.pop_back();
    }

    vector<vector<array<int, 2>>> dp(A.size() + 1, vector<array<int, 2>>(N + 1, {0, 0}));
    dp[0][0][1] = 1;
    for (int i = 0; i < (int) A.size(); i++) {
      for (int j = 0; j <= N; j++) {
        for (int k = 0; k < 2; k++) {
          Radd(dp[i + 1][j][0], dp[i][j][k]);
          if (abs(j + A[i]) <= N) {
            Radd(dp[i + 1][abs(j + A[i])][k], dp[i][j][k]);
          }
          if (abs(j - A[i]) <= N) {
            Radd(dp[i + 1][abs(j - A[i])][k], dp[i][j][k]);
          }
        }
      }
    }

    if (last == 0) {
      Radd(ans, dp[A.size()][0][1]);
      continue;
    }
    
    for (int i = 0; i < cnt[last]; i++) {
      Radd(ans, dp[A.size()][last - 1][1]);
      Radd(ans, dp[A.size()][last - 1][1]);  
      for (int i = 0; i <= last - 2; i++) {
        Radd(ans, dp[A.size()][i][0]);
        Radd(ans, dp[A.size()][i][1]);
        Radd(ans, dp[A.size()][i][0]);
        Radd(ans, dp[A.size()][i][1]);
      }
    }
  }

  cout << ans << "\n";
  return 0;
}
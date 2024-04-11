#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, m, k;
int hor[N][N], ver[N][N];
int dp[20][N][N];

bool is_inside(int u, int v) {
  return u >= 1 && u <= n && v >= 1 && v <= m;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      cin >> hor[i][j];
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> ver[i][j];
    }
  }
  if (k % 2) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
    }
    return 0;
  }
  k /= 2;
  for (int it = 0; it < k; it++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {

        auto Update = [&](int it ,int u, int v, int w) {
          if (!is_inside(u, v)) return;
          if (!dp[it][u][v]) dp[it][u][v] = w;
          else dp[it][u][v] = min(dp[it][u][v], w);
        };

        Update(it + 1, i, j + 1, dp[it][i][j] + 2 * hor[i][j]);
        Update(it + 1, i, j - 1, dp[it][i][j] + 2 * hor[i][j - 1]);
        Update(it + 1, i + 1, j, dp[it][i][j] + 2 * ver[i][j]);
        Update(it + 1, i - 1, j, dp[it][i][j] + 2 * ver[i - 1][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << dp[k][i][j] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
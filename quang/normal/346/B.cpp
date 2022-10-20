#include <bits/stdc++.h>

using namespace std;

const int N = 110;

char a[N], b[N], c[N];
int n, m, q;
int t[N];
int dp[N][N][N];
int pre[N][N][N];

void go(int u, int v, int l) {
  if (u == 0 || v == 0) {
    return;
  }
  if (pre[u][v][l] >= 0) {
    go(u - 1, v - 1, pre[u][v][l]);
    cout << a[u];
    return;
  }
  if (dp[u][v][l] == dp[u - 1][v][l]) {
    go(u - 1, v, l);
  } else {
    go(u, v - 1, l);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> (a + 1) >> (b + 1) >> (c + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  q = strlen(c + 1);
  t[1] = 0;
  memset(pre, -1, sizeof pre);
  int pos = 0;
  for (int i = 2; i <= q; i++) {
    while (pos && c[i] != c[pos + 1]) {
      pos = t[pos];
    }
    pos += (c[i] == c[pos + 1]);
    t[i] = pos;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int k = 0; k < q; k++) {
        if (a[i] == b[j]) {
          int xpos = k;
          while (xpos && a[i] != c[xpos + 1]) {
            xpos = t[xpos];
          }
          xpos += (a[i] == c[xpos + 1]);
          if (xpos < q) {
            if (dp[i][j][xpos] < dp[i - 1][j - 1][k] + 1) {
              dp[i][j][xpos] = dp[i - 1][j - 1][k] + 1;
              pre[i][j][xpos] = k;
            }
          }
        }
        if (dp[i][j][k] < dp[i - 1][j][k]) {
          dp[i][j][k] = dp[i - 1][j][k];
          pre[i][j][k] = -1;
        }
        if (dp[i][j][k] < dp[i][j - 1][k]) {
          dp[i][j][k] = dp[i][j - 1][k];
          pre[i][j][k] = -1;
        }
      }
    }
  }
  int res = 0, x = 0;
  for (int i = 0; i < q; i++) {
    if (res < dp[n][m][i]) {
      res = dp[n][m][i];
      x = i;
    }
  }
  if (!res) {
    cout << 0 << endl;
    return 0;
  }
  //cout << res << endl;
  go(n, m, x);
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 4010;

int n, m, ti, td, tr, te;
int last[30];
int pa[N][30], pb[N][30];
char a[N], b[N];
long long dp[N][N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> ti >> td >> tr >> te;
  cin >> (a + 1) >> (b + 1);
  n = strlen(a + 1);
  m = strlen(b + 1);
  for (int i = 1; i <= n; i++) {
    last[a[i] - 'a'] = i;
    for (int j = 0; j < 30; j++) {
      pa[i][j] = last[j];
    }
  }
  memset(last, 0, sizeof last);
  for (int i = 1; i <= m; i++) {
    last[b[i] - 'a'] = i;
    for (int j = 0; j < 30; j++) {
      pb[i][j] = last[j];
    }
  }
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i + j == 0) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = (1ll << 60);
      if (i && j) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + tr);
      }
      if (j) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + ti);
      }
      if (i) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + td);
      }
      if (i && j && a[i] == b[j]) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
      }
      if (i > 1 && j > 1) {
        int prea = pa[i - 1][b[j] - 'a'];
        int preb = pb[j - 1][a[i] - 'a'];
        if (prea && preb) {
          dp[i][j] = min(dp[i][j], dp[prea - 1][preb - 1] + 1ll * td * (i - prea - 1) + 1ll * ti * (j - preb - 1) + te);
        }
      }
    }
  }
  cout << dp[n][m];
  return 0;
}
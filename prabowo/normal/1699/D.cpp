#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n;
int a[N];

bool can[N][N];

int solve() {
  scanf("%d", &n);
  vector<bool> contains(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    --a[i];
  }

  for (int i = 0; i < n; ++i) {
    vector<int> cnt(n);
    int m = 0;
    can[i][i] = true;
    for (int j = i; j < n; ++j) {
      m = max(m, ++cnt[a[j]]);
      can[i][j + 1] = m * 2 <= j - i + 1;
    }
  }
  can[n][n] = true;

  vector<int> dp(n, -n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0 && can[0][i]) dp[i] = 1;
    for (int j = i; j > 0; j -= 2) {
      if (can[j][i] && a[j - 1] == a[i]) {
        dp[i] = max(dp[i], dp[j - 1] + 1);
      }
    }
    if (can[i + 1][n] && (n - i - 1) % 2 == 0) ans = max(ans, dp[i]);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}
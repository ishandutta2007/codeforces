#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
char s[4][N];

int solve() {
  scanf("%d %d %*d", &n, &m);
  for (int i = 0; i < 4; ++i) scanf("%s", s[i]);

  int ans = n + m;
  for (int k = 0; k < 2; ++k) {
    int dp[2] = {0, 0};

    for (int i = 0; i < m; ++i) {
      ++dp[s[2][i] == 'B'];
    }

    for (int i = 0; i < n; ++i) {
      ++dp[s[0][i] == 'B'];
      ++dp[s[1][i] == 'B'];

      dp[0] = min(dp[0], dp[1] + m);
      dp[1] = min(dp[1], dp[0] + m);
    }

    for (int i = 0; i < m; ++i) {
      ++dp[s[3][i] == 'B'];
    }

    ans = min(ans, min(dp[0], dp[1]));

    for (int i = 0; i < max(n, m); ++i) swap(s[0][i], s[2][i]), swap(s[1][i], s[3][i]);
    swap(n, m);
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}
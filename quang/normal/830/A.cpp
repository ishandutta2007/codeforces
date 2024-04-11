#include <bits/stdc++.h>

using namespace std;

const int N = 2020;
const long long INF = (1ll << 60);

int n, k, p;
int a[N], b[N];
long long dp[N][N];

long long get(long long u, long long v) {
  if (u <= v && v <= p) {
    return p - u;
  }
  if (p <= v && v <= u) {
    return u - p;
  }
  return abs(u - p) + min(abs(u - v), abs(p - v)) * 2ll;
}

int main() {
  scanf("%d %d %d", &n, &k, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= k; i++) {
    scanf("%d", b + i);
  }
  sort(a + 1, a + n + 1);
  sort(b + 1, b + k + 1);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= k; j++) {
      dp[i][j] = INF;
      long long foo = get(a[i], b[j]);
      dp[i][j] = min(dp[i][j], max(dp[i - 1][j - 1], foo));
      if (j > i) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[n][k] << endl;
  return 0;
}
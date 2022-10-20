#include <bits/stdc++.h>

using namespace std;

const int N = 300100;

int n, k;
int a[N];
long long dp[5010][5010];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int x = n % k;
  int y = k - x;
  int r = n / k;
  for (int i = 0; i <= x; i++) {
    for (int j = 0; j <= y; j++) {
      if (i == 0 && j == 0) {
        dp[i][j] = 0;
        continue;
      }
      dp[i][j] = (1ll << 60);
      int sum = i * (r + 1) + j * r;
      if (i) {
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[sum] - a[sum - r]);
      }
      if (j) {
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[sum] - a[sum - r + 1]);
      }
    }
  }
  cout << dp[x][y];
  return 0;
}
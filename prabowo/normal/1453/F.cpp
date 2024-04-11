#include <bits/stdc++.h>
using namespace std;
 
const int N = 3005;

int n;
int a[N];
int dp[N][N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int i = 1; i < n; ++i) {
    int cnt = 0;
    for (int j = 0; j < n; ++j) dp[i][j] = N;
    for (int j = i - 1; j >= 0; --j) {
      if (j + a[j] >= i) dp[i][j + a[j]] = min(dp[i][j + a[j]], dp[j][i - 1] + cnt++);
    }
    for (int j = 1; j < n; ++j) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
  }

  printf("%d\n", dp[n - 1][n - 1]);
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
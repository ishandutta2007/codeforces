#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;

int n;
int a[N];
int dp[N];
 
int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  int ans = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = 1;
    if (a[0] < a[i-1]) dp[i] = 2;
    for (int j = 2; j*j <= i; ++j) {
      if (i % j != 0) continue;
      if (a[j-1] < a[i-1]) dp[i] = max(dp[i], dp[j] + 1);
      if (a[i/j-1] < a[i-1]) dp[i] = max(dp[i], dp[i/j] + 1);
    }

    ans = max(ans, dp[i]);
  }
  printf("%d\n", ans);
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}
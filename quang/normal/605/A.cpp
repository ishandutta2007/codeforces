#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int main() {
  int n;
  int a[N];
  int dp[N];
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    dp[i] = -2e9;
  }
  dp[0] = 0;
  int res = 0;
  for (int i = 1; i <= n; i++) {
    dp[a[i]] = dp[a[i] - 1] + 1;
    dp[a[i]] = max(dp[a[i]], 1);
    res = max(res, dp[a[i]]);
  }
  cout << n - res << endl;
  return 0;
}
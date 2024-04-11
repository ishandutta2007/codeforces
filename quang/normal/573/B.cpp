#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int h[N];
int dp[N];
int res = 0;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
    dp[i] = 1000000000;
  }
  int maxval = 0;
  for (int i = 1; i <= n; i++) {
    maxval = min(maxval, h[i] - i);
    dp[i] = min(dp[i], i + maxval);
  }
  maxval = n + 1;
  for (int i = n; i; i--) {
    maxval = min(maxval, h[i] + i);
    dp[i] = min(dp[i], maxval - i);
  }
  for (int i = 1; i <= n; i++) {
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
}
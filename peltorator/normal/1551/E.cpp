#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i] = i + 1 - a[i];
  }
  vector<int> dp(n, -1);
  int ans = -1;
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0) {
      dp[i] = 0;
      for (int j = 0; j < i; j++) {
        if (b[j] >= 0 && b[j] <= b[i] && a[j] < a[i]) {
          dp[i] = max(dp[i], dp[j]);
        }
      }
      dp[i]++;
      if (dp[i] >= k) {
        if (ans == -1 || ans > b[i]) {
          ans = b[i];
        }
      }
    }
  }
  cout << ans << '\n';
  return;
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
}
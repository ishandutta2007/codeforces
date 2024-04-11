#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  const int MAX = 2005;
  vector<int> dp(MAX, 1e9);
  vector<int> ndp(MAX, 1e9);
  for (int i = 0; i < MAX; i++) {
    dp[i] = i;
  }
  for (int i = n - 1; i >= 0; i--) {
    int x = a[i];
    iota(begin(ndp), end(ndp), 1e9);
    for (int j = 0; j < MAX; j++) {
      if (j >= x) {
        ndp[j] = min(ndp[j], dp[j - x]);
      }
      if (j + x < MAX) {
        ndp[j] = min(ndp[j], dp[j + x]);
      }
      ndp[j] = max(ndp[j], j);
    }
    swap(dp, ndp);
  }
  int ans = 1e9;
  for (int i = 0; i < MAX; i++) {
    ans = min(ans, dp[i]);
  }
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
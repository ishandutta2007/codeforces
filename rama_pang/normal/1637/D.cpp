#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  const int MAX = 1e4 + 5;
  vector<int> dp(MAX, 1e9);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[0] += a[i] * a[i] * (n - 1);
    dp[0] += b[i] * b[i] * (n - 1);
  }
  int sumBoth = 0;
  for (int i = 0; i < n; i++) {
    vector<int> ndp(MAX, 1e9);
    for (int r = 0; r < 2; r++) {
      swap(a[i], b[i]);
      for (int j = 0; j < MAX; j++) {
        int k = sumBoth - j;
        if (j + a[i] < MAX) {
          ndp[j + a[i]] = min(ndp[j + a[i]], dp[j] +  2 * a[i] * j + 2 * b[i] * k);
        }
      }
    }
    sumBoth += a[i] + b[i];
    dp = ndp;
  }
  cout << *min_element(begin(dp), end(dp)) << '\n';
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
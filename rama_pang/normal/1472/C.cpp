#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> dp(n);
  for (int i = n - 1; i >= 0; i--) {
    dp[i] = a[i];
    if (i + a[i] < n) {
      dp[i] += dp[i + a[i]];
    }
  }
  cout << *max_element(begin(dp), end(dp)) << '\n';
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
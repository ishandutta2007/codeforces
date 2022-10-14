#include <bits/stdc++.h>
using namespace std;

template<typename T>
void ckmin(T &a, const T &b) { a = min(a, b); }

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e9));
  dp[0][0] = 0;
  for (int pos = 0; pos < n; pos++) {
    for (int inter = 0; inter <= n; inter++) {
      if (inter < n) {
        ckmin(dp[pos][inter + 1], dp[pos][inter] + 1);
      }
      if (a[pos] <= inter) {
        ckmin(dp[pos + 1][min(inter, a[pos])], dp[pos][inter]);
      } else {
        ckmin(dp[pos + 1][min(inter, a[pos])], dp[pos][inter] + 1);
      }
    }
  }

  cout << *min_element(begin(dp[n]), end(dp[n])) << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, l, r, h;
  cin >> n >> h >> l >> r;

  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  vector<int> dp(h, -1e9), nxt_dp(h, -1e9);

  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    nxt_dp.assign(h, -1e9);
    for (int j = 0; j < h; j++) {
      nxt_dp[(j + a[i]) % h] = max(nxt_dp[(j + a[i]) % h], dp[j]);
      nxt_dp[(j + a[i] - 1 + h) % h] = max(nxt_dp[(j + a[i] - 1 + h) % h], dp[j]);
    }
    for (int j = l; j <= r; j++) {
      nxt_dp[j]++;
    }
    swap(dp, nxt_dp);
  }

  cout << *max_element(begin(dp), end(dp)) << "\n";
  return 0;
}
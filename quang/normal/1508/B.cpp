#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    long long k;
    cin >> n >> k;
    k--;
    int cur = 1;
    vector<int> res;
    while (cur <= n) {
      int len = 1;
      while (cur + len <= n && (1ll << n - cur - len) <= k && n - cur - len < 61) {
        k -= (1ll << n - cur - len);
        len++;
      }
      for (int i = 0; i < len; i++) {
        res.push_back(cur + len - i - 1);
      }
      cur += len;
    }
    if (k > 0) cout << -1 << '\n';
    else {
      for (auto u : res) cout << u << ' ';
        cout << '\n';
    }
  }
  return 0;
}
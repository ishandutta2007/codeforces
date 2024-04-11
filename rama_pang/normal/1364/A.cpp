#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    int nt = 0;
    for (auto &i : a) {
      cin >> i;
      if (i % x != 0) {
        nt = 1;
      }
    }
    if (!nt) {
      cout << -1 << "\n";
      continue;
    }
    int l = 0, r = n - 1;
    int all = 0;
    for (auto i : a) all += i;
    if (all % x != 0) {
      cout << n << "\n";
      continue;
    }
    int ans = 0;
    for (int i = 0, s = 0; i < n; i++) {
      s += a[i];
      if (s % x != 0) {
        ans = max(ans, n - i - 1);
      }
    }
    for (int i = n - 1, s = 0; i >= 0; i--) {
      s += a[i];
      if (s % x != 0) {
        ans = max(ans, i);
      }
    }
    cout << ans << "\n";
  }
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint n, m;
    cin >> n >> m;
    vector<lint> a(n);
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      for (int j = 0; j < m; j++) {
        if (s[j] == '1') {
          a[i] |= 1ll << (m - j - 1);
        }
      }
    }

    auto Count = [&](lint x) {
      lint res = x + 1;
      for (int i = 0; i < n; i++) {
        if (a[i] <= x) {
          res--;
        }
      }
      return res;
    };

    lint lo = 0, hi = (1ll << m) - 1;
    lint median = ((1ll << m) - n - 1) / 2 + 1;
    while (lo < hi) {
      lint mid = (lo + hi) / 2;
      if (Count(mid) >= median) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }

    string ans(m, '0');
    for (int i = 0; i < m; i++) {
      if (hi & (1ll << i)) {
        ans[m - i - 1] = '1';
      }
    }
    cout << ans << "\n";
  }
}
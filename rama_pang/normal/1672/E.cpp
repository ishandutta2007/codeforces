#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;

  const auto Query = [&](int x) {
    cout << "? " << x << endl;
    int y;
    cin >> y;
    return y;
  };

  int lo = 1, hi = 1e7;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    int q = Query(md);
    if (q != 1) {
      lo = md + 1;
    } else {
      hi = md;
    }
  }

  int mx = 0;
  int ans = 1e9;
  // for (int sumW = n; sumW <= n * 2000; sumW++) {
    vector<pair<int, int>> rects;
    int sumW = hi - (n - 1);
    for (int i = 0; i < n; i++) {
      // if we fix i, the number of spaces
      int x = sumW + i;
      for (int y = n - i; y <= n; y++) {
        if (x % y == 0) {
          rects.emplace_back(y, x / y);
        }
      }
    }    
    for (auto [x, y] : rects) {
      assert(x <= n);
      if (Query(y) == x) {
        ans = min(ans, x * y);
      }
    }
    // cout << rects.size() << '\n';
    // mx = max(mx, int(rects.size()));

  // }
  cout << "! " << ans << endl;

  // cout << ans << '\n';
  // find sumW
  // sumW / 1, sumW / 2, 
  // extra space is N-1
  // answer is either:
  // sumW + i for 0 <= i <= N-1
  // for sumW + i, let j = N - i
  // then we need j or more lines at minimum
  // since one "enter" can only erase one space
  // 
  // So decompose
  // 2 * sumW / 2
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
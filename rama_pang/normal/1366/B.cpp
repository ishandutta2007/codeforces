#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x, m;
    cin >> n >> x >> m;
    int lo = x, hi = x;
    for (int i = 0; i < m; i++) {
      int l, r;
      cin >> l >> r;
      if (lo <= r) lo = min(lo, l);
      if (l <= hi) hi = max(hi, r);
    }
    cout << (hi - lo + 1) << "\n";
  }
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  lint t, x, y;
  cin >> t >> x >> y;
  while (t--) {
    lint a;
    cin >> a;
    lint lo = 0, hi = 1e18;
    while (lo < hi) {
      lint md = (lo + hi) / 2;
      lint hits = md / x + md / y;
      if (hits >= a) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    // cout << lo << "\n";
    if (lo % x == 0 && lo % y == 0) {
      cout << "Both\n";
    } else if (lo % x == 0) {
      cout << "Vova\n";
    } else {
      cout << "Vanya\n";
    }
  }

  return 0;
}
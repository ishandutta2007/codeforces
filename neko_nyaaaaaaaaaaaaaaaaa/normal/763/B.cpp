#include <bits/stdc++.h>
using namespace std;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cout << "YES\n";
      int x1, y1, x2, y2; cin >> x1;
      while (cin >> x1 >> y1 >> x2 >> y2) {
            int x = abs(min(x1, x2)) % 2;
            int y = abs(min(y1, y2)) % 2;

            cout << x*2 + y + 1 << '\n';
      }

      return 0;
}
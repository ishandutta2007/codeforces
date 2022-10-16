#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      int ans = 0;
      while (n--) {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            ans += (abs(x1 - x2) + 1)*(abs(y1 - y2) + 1);
      }
      cout << ans << '\n';

      return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n; cin >> n;
      ll ans = 0;
      ll lo = 1, hi = 9;
      ll dig = 1;
      while (lo <= n) {
            ans += (min(n, hi) - lo + 1)*dig;
            dig++;
            lo *= 10;
            hi = lo*10 - 1;
      }
      cout << ans;

      return 0;
}
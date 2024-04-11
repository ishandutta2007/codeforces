#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll la, ra, ta, lb, rb, tb;
      cin >> la >> ra >> ta >> lb >> rb >> tb;

      if (ta == tb) {
            ll l = max(la, lb);
            ll r = min(ra, rb);
            cout << max(0LL, r - l + 1); return 0;
      }

      ll g = __gcd(ta, tb);
      if (la > lb) {
            swap(ta, tb);
            swap(la, lb);
            swap(ra, rb);
      }

      ll k = (lb - la)/g;

      ll ans = 0;
      for (int i = -1; i <= 1; i++) {
            ll l = max(la + (k+i)*g, lb);
            ll r = min(ra + (k+i)*g, rb);
            ans = max(ans, r-l+1);
      }
      cout << ans;

      return 0;
}
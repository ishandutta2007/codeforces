#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll a, b; cin >> a >> b;
      if ((a == 2 && b == 2)) {cout << 0; return 0;}
      if (a > b) swap(a, b);
      if (a == 1) {
            if (b % 6 == 0) {cout << b;}
            else if (b % 6 == 1 || b % 6 == 5) {cout << b-1;}
            else if (b % 6 == 3) {cout << b-3;}
            else {cout << b-2;}
            return 0;
      }
      if (a >= 5) {
            ll ans = a*b;
            if (ans % 2) ans--;
            cout << ans; return 0;
      }
      if (a == 2) {
            if (b == 3) {cout << 4; return 0;}
            if (b == 7) {cout << 12; return 0;}
            cout << a*b; return 0;
      }
      if (a == 3) {
            ll ans = a*b;
            if (b % 2) ans--;
            cout << ans; return 0;
      }
      if (a == 4) {
            cout << a*b; return 0;
      }

      return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll a, b, x, y; cin >> a >> b >> x >> y;
      ll k = __gcd(x, y);
      x /= k;
      y /= k;

      ll ans = min(a/x, b/y);
      cout << ans;

      return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      ll n; cin >> n;
      if (n == 1) {cout << "1 0"; return 0;}
      vector<ll> pw;
      ll ans = 1;
      for (ll i = 2; i <= n; i++) {
            if (n % i == 0) {
                  ans *= i;
                  ll p = 0;
                  while (n % i == 0) {
                        n /= i;
                        p++;
                  }
                  pw.push_back(p);
            }
      }
      sort(pw.begin(), pw.end());

      ll mx = 1; ll ans2 = 0;
      for (; mx < pw.back(); mx *= 2) {
            ans2++;
      }

      cout << ans << ' ';

      for (ll i: pw) {
            if (i != mx) {ans2++; break;}
      }
      cout << ans2;

      return 0;
}
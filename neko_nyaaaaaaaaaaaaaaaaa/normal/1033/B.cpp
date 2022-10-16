#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int check(ll n) {
      for (ll i = 2; i*i <= n; i++) {
            if (n % i == 0) return 0;
      }
      return 1;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int t; cin >> t;
      while (t--) {
            ll a, b; cin >> a >> b;
            if (a-b != 1) {cout << "NO\n";}
            else {
                  ll k = a+b;
                  if (check(k)) {cout << "YES\n";}
                  else cout << "NO\n";
            }
      }

	return 0;
}
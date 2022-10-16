#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pr(ll s) {
      for (ll i = 2; i*i <= s; i++) {
            if (s % i == 0) return i;
      }
      return 0;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      ll n; cin >> n;
      ll sum = n*(n+1)/2;

      ll k = pr(sum);
      if (k == 0) {cout << "No"; return 0;}

      cout << "Yes\n";
      cout << "1 " << k << "\n";
      cout << n-1 << " ";
      for (int i = 1; i <= n; i++) {
            if (i != k) cout << i << " ";
      }

	return 0;
}
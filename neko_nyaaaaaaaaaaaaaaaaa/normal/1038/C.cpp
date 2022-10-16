#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<ll> a(n+1), b(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }
      for (int i = 1; i <= n; i++) {
            cin >> b[i];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());

      ll as = 0, bs = 0;
      int aturn = 1;
      int petra = n, petrb = n;
      while (petra || petrb) {
            if (b[petrb] > a[petra]) {
                  if (!aturn) {
                        bs += b[petrb];
                  }
                  petrb--;
            } else {
                  if (aturn) {
                        as += a[petra];
                  }
                  petra--;
            }
            aturn ^= 1;
      }
      cout << as - bs;

	return 0;
}
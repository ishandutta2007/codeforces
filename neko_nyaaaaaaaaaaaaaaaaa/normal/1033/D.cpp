#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      map<ll, ll> div;
      vector<ll> a;
      while (n--) {
            ll x; cin >> x;
            ll k1 = sqrtl(x);
            ll k2 = sqrtl(k1);
            ll kc = cbrtl(x);

            if (kc*kc*kc == x) {
                  div[kc] += 3;
                  continue;
            }

            if (k2*k2*k2*k2 == x) {
                  div[k2] += 4;
                  continue;
            }

            if (k1*k1 == x) {
                  div[k1] += 2;
                  continue;
            }

            a.push_back(x);
      }
      n = a.size();

      ll g[n][n];
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  g[i][j] = __gcd(a[i], a[j]);
            }
      }

      vector<pair<ll, ll>> d(n);
      for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                  if (g[i][j] != a[i] && g[i][j] != 1) {
                        d[i].first = a[i]/g[i][j];
                        d[i].second = g[i][j];
                        break;
                  }
            }

            if (d[i].first) continue;

            for (auto u: div) {
                  if (a[i] % u.first == 0) {
                        d[i].first = a[i]/u.first;
                        d[i].second = u.first;
                  }
            }
      }

      map<ll, ll> surplus;
      for (int i = 0; i < n; i++) {
            if (d[i].first == 0) {
                  surplus[a[i]]++;
            } else {
                  div[d[i].first]++;
                  div[d[i].second]++;
            }
      }

      ll ans = 1;
      ll M = 998244353;
      for (auto u: div) {
            ans *= (u.second+1);
            ans %= M;
      }

      for (auto u: surplus) {
            ans *= (u.second+1);
            ans *= (u.second+1);
            ans %= M;
      }
      cout << ans;

	return 0;
}
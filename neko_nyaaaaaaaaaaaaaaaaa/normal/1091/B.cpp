#include <bits/stdc++.h>
using namespace std;

#define int long long

int modpow(int n, int k, int MOD);

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> x(n), y(n), a(n), b(n);
      for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
      }
      for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
      }

      set<pair<int, int>> s;
      for (int i = 0; i < n; i++) {
            s.insert({x[0] + a[i], y[0] + b[i]});
      }

      for (int j = 1; j < n; j++) {
            set<pair<int, int>> ss;
            for (int i = 0; i < n; i++) {
                  ss.insert({x[j] + a[i], y[j] + b[i]});
            }

            set<pair<int, int>> nw;
            for (auto it = s.begin(); it != s.end(); it++) {
                  if (ss.find(*it) != ss.end()) {
                        nw.insert(*it);
                  }
            }
            swap(s, nw);
      }

      auto u = *s.begin();
      cout << u.first << ' ' << u.second;

      return 0;
}

int modpow(int n, int k, int MOD) {
      if (k == 0) return 1;
      int tmp = modpow(n, k/2, MOD);
      tmp = (tmp*tmp) % MOD;
      if (k % 2) tmp = (tmp*n) % MOD;
      return tmp;
}
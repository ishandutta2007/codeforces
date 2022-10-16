#include <bits/stdc++.h>
using namespace std;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      long long n, k; cin >> n >> k;
      long long b = (1LL << k) - 1;
      long long ans = n*(n-1)/2 + n;

      map<long long, long long> m;
      long long xr = 0;
      for (int i = 0; i < n; i++) {
            long long x; cin >> x;
            long long y = x^b;

            if (i == 0) {m[max(x,y)]++; xr = max(x, y);}
            else {
                  if (m[x^xr] < m[y^xr] || (x != xr && m[x^xr] == m[y^xr])) {
                        m[x^xr]++;
                        xr ^= x;
                  } else {
                        m[y^xr]++;
                        xr ^= y;
                  }
            }
      }

      for (auto u: m) {
            long long x = u.second;
            ans -= x*(x-1)/2;
            if (u.first == 0) {ans -= x;}
      }

      cout << ans;

      return 0;
}
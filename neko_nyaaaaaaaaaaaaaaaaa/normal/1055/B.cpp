#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m, l; cin >> n >> m >> l;
      vector<int> a(n+3);
      vector<int> b(n+3);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = (a[i] > l);
      }
      int ans = 0;
      for (int i = 1; i <= n; i++) {
            if (b[i] && !b[i-1]) {ans++;}
      }

      while (m--) {
            int q; cin >> q;
            if (q == 0) {
                  cout << ans << '\n';
            } else {
                  int p, d; cin >> p >> d;
                  if (b[p]) {
                        continue;
                  } else {
                        a[p] += d;
                        if (a[p] > l) {
                              b[p] = 1;
                              ans++;
                              if (b[p-1]) ans--;
                              if (b[p+1]) ans--;
                        }
                  }
            }
      }

      return 0;
}
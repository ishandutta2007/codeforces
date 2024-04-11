#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n, m; cin >> n >> m;
      vector<tuple<int, int, int, int>> tp(n);
      vector<int> k(n), kk(n);
      for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            int z = y - x;
            k[i] = x; kk[i] = y;
            tp[i] = make_tuple(z, x, y, i);
      }
      sort(tp.begin(), tp.end());

      vector<int> x(n), y(n), id(n), xx(n), yy(n);
      for (int i = 0; i < n; i++) {
            int a, b, c, d;
            tie(a, b, c, d) = tp[i];
            x[i] = b, y[i] = c, id[i] = d;
      }
      xx = x; yy = y;
      for (int i = 1; i < n; i++) {
            y[i] += y[i-1];
      }
      for (int i = n-2; i >= 0; i--) {
            x[i] += x[i+1];
      }

      vector<int> ans(n);
      for (int i = 0; i < n; i++) {
            int ind = id[i];
            if (i > 0) {
                  ans[ind] += xx[i]*i + y[i-1];
            }
            if (i < n-1) {
                  ans[ind] += yy[i]*(n-i-1) + x[i+1];
            }
      }

      while (m--) {
            int u, v; cin >> u >> v;
            u--; v--;
            int kkk = min(k[u] + kk[v], kk[u] + k[v]);
            ans[u] -= kkk;
            ans[v] -= kkk;
      }

      for (int i: ans) cout << i << ' ';

      return 0;
}
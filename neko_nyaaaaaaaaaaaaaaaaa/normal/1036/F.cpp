#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int m = 1e18;
      vector<int> ans;
      for (int i = 2; i <= 1000000; i++) {
            for (int j = i*i*i; j <= m; j *= i) {
                  int k = sqrtl(j);
                  if (k*k != j) ans.push_back(j);
                  if (j > m / i) break;
            }
      }
      sort(ans.begin(), ans.end());
      ans.erase(unique(ans.begin(), ans.end()), ans.end());

      int q; cin >> q;
      while (q--) {
            int l = 2, r; cin >> r;
            int x = sqrtl(r), y = sqrtl(l-1);
            int z = upper_bound(ans.begin(), ans.end(), r) - lower_bound(ans.begin(), ans.end(), l);
            cout << max(0LL, r - (x - y + z) - 1) << '\n';
      }

      return 0;
}
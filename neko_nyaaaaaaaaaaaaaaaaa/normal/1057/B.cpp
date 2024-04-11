#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[i] += a[i-1];
      }

      int ans = 0;
      for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                  if (a[j] - a[i-1] > 100*(j - i + 1)) {
                        ans = max(ans, j - i + 1);
                  }
            }
      }
      cout << ans;

      return 0;
}
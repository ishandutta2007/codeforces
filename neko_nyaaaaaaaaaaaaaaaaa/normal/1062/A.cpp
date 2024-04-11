#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n+1);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }
      a.push_back(1001);

      int ans = 0;
      int cur = 1;
      for (int i = 1; i <= n+1; i++) {
            if (a[i] == a[i-1] + 1) {
                  cur++;
            } else {
                  if (cur > 1) {ans = max(ans, cur - 2);}
                  cur = 1;
            }
      }
      if (cur > 1) {ans = max(ans, cur - 2);}

      cout << ans;

      return 0;
}
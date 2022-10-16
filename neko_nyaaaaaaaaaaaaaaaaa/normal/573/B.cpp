#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a(n+2);
      for (int i = 1; i <= n; i++) {
            cin >> a[i];
      }

      vector<int> dp1(n+2);
      for (int i = 1; i <= n; i++) {
            dp1[i] = min(dp1[i-1] + 1, a[i]);
      }
      vector<int> dp2(n+2);
      for (int i = n; i; i--) {
            dp2[i] = min(dp2[i+1] + 1, a[i]);
      }

      int ans = 0;
      for (int i = 1; i <= n; i++) {
            ans = max(ans, min(dp1[i], dp2[i]));
      }
      cout << ans;

      return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
unordered_set<int> s;
vector<int> fi(5001, -1);
vector<int> se(5001, -1);

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      vector<int> a(n);

      for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
      }

      for (int val: s) {
            int first = -1, last;
            for (int i = 0; i < n; i++) {
                  if (a[i] == val) {
                        if (first == -1) first = i;
                        last = i;
                  }
            }

            fi[val] = first;
            se[val] = last;
      }

      vector<int> dp(5001);
      for (int i = 0; i < n; i++) {
            s.clear();
            int xr = 0;
            dp[i] = (i == 0 ? 0 : dp[i-1]);

            int mn = 10000, mx = -10000;
            for (int j = i; j >= 0; j--) {
                  mn = min(mn, fi[a[j]]);
                  mx = max(mx, se[a[j]]);

                  if (s.find(a[j]) == s.end()) {
                        s.insert(a[j]);
                        xr ^= a[j];
                  }

                  if (j == mn && i == mx) {
                        dp[i] = max(dp[i], xr + (j == 0 ? 0 : dp[j-1]));
                  }
            }
      }
      cout << dp[n-1];

      return 0;
}
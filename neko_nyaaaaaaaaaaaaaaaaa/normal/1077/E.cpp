#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      map<int, int> m;
      for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
      }

      vector<int> a;
      for (auto u: m) {
            a.push_back(u.second);
      }
      sort(a.begin(), a.end());

      int ans = 0; int mx = a.back();
      int petr = 0;
      for (int i = 1; i <= mx; i++) {
            int k = 0; petr = 0;
            int c = i;
            while (petr != a.size()) {
                  auto p = lower_bound(a.begin() + petr, a.end(), c);
                  if (p == a.end()) break;
                  petr = p - a.begin() + 1;

                  k += c; c *= 2;
            }
            if (k > ans) {
                  ans = k;
            }
      }
      cout << ans;

      return 0;
}
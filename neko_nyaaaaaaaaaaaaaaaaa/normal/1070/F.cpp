#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> a[12];
      for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            a[x].push_back(y);
      }
      for (int i = 0; i < 12; i++) {
            sort(a[i].begin(), a[i].end());
      }
      int ans = 0;

      while (a[1].size() && a[10].size()) {
            ans += a[1].back(); a[1].pop_back();
            ans += a[10].back(); a[10].pop_back();
      }
      while (a[1].size() || a[10].size()) {
            if (a[1].size()) {a[0].push_back(a[1].back()); a[1].pop_back();}
            if (a[10].size()) {a[0].push_back(a[10].back()); a[10].pop_back();}
      }
      sort(a[0].begin(), a[0].end());

      while (a[11].size() && a[0].size()) {
            ans += a[0].back(); a[0].pop_back();
            ans += a[11].back(); a[11].pop_back();
      }

      while (a[11].size()) {
            ans += a[11].back(); a[11].pop_back();
      }

      cout << ans;

      return 0;
}
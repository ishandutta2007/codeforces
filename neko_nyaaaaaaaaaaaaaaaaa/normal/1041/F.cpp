#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      map<int, int> mm;

      int n, y1; cin >> n >> y1;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {cin >> a[i]; mm[a[i]]++;}
      int m, y2; cin >> m >> y2;
      vector<int> b(m);
      for (int i = 0; i < m; i++) {cin >> b[i]; mm[b[i]]++;}

      int ans = 0;
      for (auto u: mm) ans = max(ans, u.second);

      for (int j = 2; j <= 1e9; j *= 2) {
            map<int, int> mp;
            for (int i = 0; i < n; i++) mp[a[i] % j]++;
            for (int i = 0; i < m; i++) mp[(b[i] + j/2) % j]++;
            for (auto u: mp) ans = max(ans, u.second);

            mp.clear();
            for (int i = 0; i < n; i++) mp[(a[i] + j/2) % j]++;
            for (int i = 0; i < m; i++) mp[b[i] % j]++;
            for (auto u: mp) ans = max(ans, u.second);
      }
      cout << ans;

      return 0;
}
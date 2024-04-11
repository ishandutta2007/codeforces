#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      int n; cin >> n;
      vector<pair<int, int>> a(n);
      for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            a[i] = {x, y};
      }

      int f3 = 0, f4 = 0;
      sort(a.begin(), a.end());
      f4 = abs(a[0].first - a[n-1].first)*2;

      int maxx = a[n-1].first;
      int minx = a[0].first;

      for (int i = 0; i < n; i++) {
            swap(a[i].first, a[i].second);
      }

      sort(a.begin(), a.end());
      f4 += abs(a[0].first - a[n-1].first)*2;

      int maxy = a[n-1].first;
      int miny = a[0].first;

      for (int i = 0; i < n; i++) {
            f3 = max(f3, abs(maxy - a[i].first) + abs(maxx - a[i].second));
            f3 = max(f3, abs(miny - a[i].first) + abs(minx - a[i].second));
            f3 = max(f3, abs(maxy - a[i].first) + abs(minx - a[i].second));
            f3 = max(f3, abs(miny - a[i].first) + abs(maxx - a[i].second));
      }

      cout << f3*2 << ' ';
      for (int i = 4; i <= n; i++) cout << f4 << ' ';
}
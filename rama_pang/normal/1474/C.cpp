#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
      cin >> a[i];
    }
    sort(begin(a), end(a));
    bool yes = false;
    for (int an = 0; an + 1 < 2 * n; an++) {
      vector<bool> used(2 * n, false);
      used[an] = true;
      const auto Get = [&](int v) {
        int l = 0, r = 2 * n;
        while (l < r) {
          int md = (l + r) / 2;
          if (a[md] < v || (a[md] == v && used[md])) {
            l = md + 1;
          } else {
            r = md;
          }
        }
        return l;
      };
      int last = 2 * n;
      vector<pair<int, int>> ans;
      for (int i = 2 * n - 1; i >= 0; i--) {
        if (used[i]) continue;
        if (last == 2 * n) {
          assert(an < i);
          ans.emplace_back(a[an], a[i]);
          last = i;
        } else {
          int need = a[last] - a[i];
          int gt = Get(need);
          if (gt < i && a[gt] == need) {
            ans.emplace_back(a[gt], a[i]);
            used[gt] = true;
            last = i;
          }
        }
      }
      if (ans.size() == n) {
        yes = true;
        cout << "YES\n";
        cout << ans[0].first + ans[0].second << '\n';
        for (auto i : ans) cout << i.first << ' ' << i.second << '\n';
        break;
      }
    }
    if (!yes) cout << "NO\n";
  }
  return 0;
}
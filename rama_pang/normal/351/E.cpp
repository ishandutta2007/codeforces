#include <bits/stdc++.h>
using namespace std;
using lint = long long;

#include <bits/extc++.h>
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  map<int, vector<int>> all;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
    all[-a[i]].emplace_back(i);
  }
  ordered_set active;
  for (int i = 0; i < n; i++) {
    active.insert(i);
  }
  int ans = 0;
  for (const auto &mp : all) {
    vector<int> cur = mp.second;
    int m = cur.size();
    for (int i = 0; i < m; i++) {
      cur[i] = active.order_of_key(cur[i]);
    }
    vector<int> p(m), s(m);
    int score = 1e9;
    for (int i = 0; i < (int) cur.size(); i++) {
      p[i] = cur[i] - i;
      if (i > 0) p[i] += p[i - 1];
    }
    for (int i = int(cur.size()) - 1; i >= 0; i--) {
      int onright = int(active.size()) - 1 - cur[i];
      int onrightsame = int(cur.size()) - 1 - i;
      s[i] = onright - onrightsame;
      if (i + 1 < (int) cur.size()) {
        s[i] += s[i + 1];
      }
    }
    score = min(p[m - 1], s[0]);
    for (int i = 0; i + 1 < (int) cur.size(); i++) {
      score = min(score, p[i] + s[i + 1]);
    }
    ans += score;
    for (auto i : mp.second) {
      active.erase(i);
    }
  }
  cout << ans << "\n";
  return 0;
}
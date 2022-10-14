#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

using lint = long long;
#define int lint

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

void Main() {
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> occ(26);
  for (int i = 0; i < n; i++) {
    occ[s[i] - 'a'].emplace_back(i);
  }
  for (int i = 0; i < 26; i++) {
    reverse(begin(occ[i]), end(occ[i]));
  }
  int ans = 1e18;
  ordered_set st;
  for (int i = 0; i < n; i++) {
    st.insert(i);
  }
  int cost = 0;
  for (int i = 0; i < n; i++) {
    int c = t[i] - 'a';
    int gt = n;
    for (int j = 0; j < c; j++) {
      if (occ[j].empty()) continue;
      gt = min(gt, occ[j].back());
    }
    if (gt < n) {
      ans = min(ans, int(cost + st.order_of_key(gt)));
    }
    if (occ[c].empty()) break;
    gt = occ[c].back();
    occ[c].pop_back();
    cost += st.order_of_key(gt);
    st.erase(gt);
  }
  if (ans > 1e15) ans = -1;
  cout << ans << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      l[i] = (i + n - 1) % n;
      r[i] = (i + 1) % n;
    }
    set<int> bad_positions;
    for (int i = 0; i < n; i++) {
      int g = __gcd(a[i], a[l[i]]);
      if (g == 1) {
        bad_positions.insert(i);
      }
    }
    vector<int> res;
    int cur_pos = 1;
    while (!bad_positions.empty()) {
      // cout << "# " << cur_pos << endl;
      // for (const auto &u : bad_positions) {
      //   cout << u << ' ';
      // }
      // cout << endl;
      auto it = bad_positions.lower_bound(cur_pos);
      if (it == bad_positions.end()) it = bad_positions.begin();      
      res.push_back(*it);
      int pos = *it;
      int l_pos = l[*it];
      int r_pos = r[*it];
      r[l_pos] = r_pos;
      l[r_pos] = l_pos;
      cur_pos = r[r_pos];
      bad_positions.erase(it);
      bad_positions.erase(r_pos);
      if (__gcd(a[l_pos], a[r_pos]) == 1 && pos != r_pos) {
        bad_positions.insert(r_pos);
      }
    }
    cout << (int)res.size() << ' ';
    for (const int &u : res) cout << u + 1 << ' ';
      cout << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s, ans;
    cin >> s;
    vector<int> all;
    for (int i = 0; i < n; i++) {
      all.emplace_back(i);
    }
    for (int i = 0; i < n; i++) {
      vector<int> one, zero;
      for (auto j : all) {
        if (s[i + j] == '0') {
          zero.emplace_back(j);
        } else {
          one.emplace_back('1');
        }
      }
      if (all.empty()) {
        ans.push_back('0');
        continue;
      }
      if (!one.empty()) {
        ans.push_back('1');
        all = zero;
      } else if (!zero.empty()) {
        ans.push_back('0');
        all = one;
      } else {
        assert(false);
      }
    }
    assert(all.empty());
    cout << ans << "\n";
  }
  return 0;
}
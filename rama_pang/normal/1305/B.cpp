#include <bits/stdc++.h>
using namespace std;
using lint = long long;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  string s;
  cin >> s;
  vector<vector<int>> ans;

  while (true) {
    string t;
    int l = 0, r = (int) s.size() - 1;
    if (l <= r) {
      vector<int> fr, bc;
      while (l <= r) {
        while (l < s.size() && s[l] != '(') {
          l++;
        }
        while (r > 0 && s[r] != ')') {
          r--;
        }
        if (l < r) {
          fr.emplace_back(l);
          bc.emplace_back(r);
          l++, r--;
        } else {
          break;
        }
      }
      reverse(begin(bc), end(bc));
      for (auto &i : bc) {
        fr.emplace_back(i);
      }
      if (fr.empty()) {
        break;
      }
      ans.emplace_back(fr);
      vector<int> done(s.size());
      for (auto &i : fr) {
        done[i] = 1;
      }
      for (int i = 0; i < s.size(); i++) {
        if (!done[i]) {
          t.push_back(s[i]);
        }
      }
      s = t;
    } else {
      break;
    }
  }

  cout << ans.size() << "\n";
  for (auto &i : ans) {
    cout << i.size() << "\n";
    for (auto &j : i) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}
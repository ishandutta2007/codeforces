#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, k;
  string s;
  cin >> n >> k;
  cin >> s;
  
  int total = 0;
  for (int i = n - 1, le = 0; i >= 0; i--) {
    if (s[i] == 'R') total += le;
    if (s[i] == 'L') le++;
  }

  if (total < k) {
    cout << -1 << "\n";
    return 0;
  }

  vector<vector<int>> ans;

  set<int> can;
  set<int> nw;
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == 'R' && s[i + 1] == 'L') {
      can.emplace(i);
    }
  }

  while (k > 0) {
    ans.emplace_back();
    int move = 0;
    while (total >= k && !can.empty()) {
      total--;
      move = 1;
      int i = *begin(can);
      swap(s[i], s[i + 1]);
      ans.back().emplace_back(i);
      can.erase(i);
      if (i + 2 < n) {
        if (s[i + 1] == 'R' && s[i + 2] == 'L') {
          nw.emplace(i + 1);
        }
      }
      if (i - 1 >= 0) {
        if (s[i - 1] == 'R' && s[i] == 'L') {
          nw.emplace(i - 1);
        }
      }
    }
    if (move == 0) {
      cout << -1 << "\n";
      return 0;
    }
    for (auto i : nw) {
      can.emplace(i);
    }
    nw.clear();
    k--;
  }

  if (total != 0) {
    cout << -1 << "\n";
    return 0;
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i].size();
    for (auto j : ans[i]) cout << " " << j + 1;
    cout << "\n";
  }

}
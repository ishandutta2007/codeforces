#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> b(n);
  vector<int> used(n + 2);
  vector<vector<int>> ls(n + 2);
  int turn = 0;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    used[b[i]] = 1;
    ls[b[i]].emplace_back(i + 1);
    if (b[i] == n + 1) turn = 1;
  }
  int mxt = 0;
  vector<int> ans;
  int lft = 0, rgt = n + 1;
  while (ans.size() < n) {
    if (turn == 0) {
      vector<int> cur = ls[lft];
      int which = -1;
      for (auto i : cur) {
        if (used[i]) {
          assert(which == -1);
          which = i;
        }
      }
      for (auto i : cur) {
        if (i != which) {
          ans.emplace_back(i);
        }
      }
      if (which == -1) break;
      ans.emplace_back(which);
      rgt = which;
    } else {
      vector<int> cur = ls[rgt];
      int which = -1;
      for (auto i : cur) {
        if (used[i]) {
          assert(which == -1);
          which = i;
        }
      }
      for (auto i : cur) {
        mxt = max(mxt, i);
        if (i != which) {
          ans.emplace_back(i);
        }
      }
      if (which == -1) break;
      ans.emplace_back(which);
      lft = which;
    }
    turn ^= 1;
  }
  assert(ans.size() == n);
  cout << mxt << '\n';
  for (auto i : ans) cout << i << ' '; cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}
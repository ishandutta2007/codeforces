#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  string s;
  cin >> s;
  int f = 0;
  for (auto u : s) {
    if (u == '0') {
      f = 1;
      break;
    }
  }
  if (!f) {
    cout << 0 << '\n';
    return;
  }
  int num = 0;
  int l = -1, r = -1;
  for (int i = 0; i < s.size(); i++) {
    auto u = s[i];
    num += u == '0';
    if (u == '0') {
      if (l == -1) l = i;
      r = i;
    }
  }
  if (num == r - l + 1) {
    cout << 1 << '\n';
    return ;
  }
  cout << 2 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
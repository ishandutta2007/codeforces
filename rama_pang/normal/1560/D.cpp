#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  string n;
  cin >> n;

  const auto Solve = [&](string a, string b) {
    int res = b.size();
    int ptr = 0;
    for (auto i : a) {
      if (ptr < b.size() && b[ptr] == i) {
        ptr += 1;
        res -= 1;
      } else {
        res += 1;
      }
    }
    return res;
  };
  int ans = 1e9;
  for (lint _ = 1; _ <= lint(1e18); _ *= 2) {
    string t = to_string(_);
    ans = min(ans, Solve(n, t));
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
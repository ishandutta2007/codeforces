#include <bits/stdc++.h>

using namespace std;

string s;

int Solve(int u) {
  if (u == s.size()) {
    int res = 0;
    int p[2] = {0, 0};
    for (int i = 0; i < 10; i++) {
      p[i % 2] += (s[i] == '1');
      int zero_kick = 5 - (i / 2 + 1);
      int one_kick = 5 - (i + 1) / 2;
      // zero lose
      if (p[0] + zero_kick < p[1]) return i + 1;
      // one lose
      if (p[1] + one_kick < p[0]) return i + 1;
    }
    return 10;
  }
  if (s[u] != '?') return Solve(u + 1);
  int res = 10;
  s[u] = '0'; res = min(res, Solve(u + 1));
  s[u] = '1'; res = min(res, Solve(u + 1));
  s[u] = '?';
  return res;
}

void solve(int test) {
  cin >> s;
  cout << Solve(0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}
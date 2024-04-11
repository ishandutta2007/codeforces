#include <bits/stdc++.h>

using namespace std;

void solve(int test) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string t = s;
  sort(t.begin(), t.end());
  int res = 0;
  for (int i = 0; i < n; i++) {
    res += t[i] != s[i];
  }
  cout << res << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) solve(test);
  return 0;
}
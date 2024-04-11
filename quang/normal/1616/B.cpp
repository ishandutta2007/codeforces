#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool found = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] > s[i + 1]) {
      found = 1;
      continue;
    }
    if (s[i] <= s[i + 1]) {
      if (s[i] == s[i + 1] && found) {
        continue;
      }
      for (int j = 0; j <= i; j++) cout << s[j];
      for (int j = i; j >= 0; j--) cout << s[j];
      cout << '\n';
      return;
    }
  }
  for (int i = 0; i < n; i++) cout << s[i];
  for (int i = n - 1; i >= 0; i--) cout << s[i];
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}
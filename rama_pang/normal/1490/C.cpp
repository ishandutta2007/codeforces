#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  map<lint, lint> mp;
  for (lint a = 1; a * a * a <= lint(1e13); a++) {
    mp[a * a * a] = a;
  }

  while (T--) {
    lint n;
    cin >> n;
    bool yes = false;
    for (lint a = 1; a * a * a <= n; a++) {
      if (mp.count(n - a * a * a)) {
        yes = true;
        break;
      }
    }
    cout << (yes ? "YES" : "NO") << '\n';
  }
  return 0;
}
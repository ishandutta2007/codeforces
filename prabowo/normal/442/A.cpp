#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n;
string s[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  map<char, int> col;
  col['R'] = 0;
  col['G'] = 1;
  col['B'] = 2;
  col['Y'] = 3;
  col['W'] = 4;

  int ans = n;
  for (int mask = 0; mask < 1 << 10; ++mask) {
    vector<string> v[11];
    for (int i = 0; i < n; ++i) {
      bool one = (mask >> col[s[i][0]] & 1);
      bool two = (mask >> s[i][1] - '1' + 5 & 1);

      if (one && two) continue;
      if (one) v[col[s[i][0]]].push_back(s[i]);
      else if (two) v[s[i][1] - '1' + 5].push_back(s[i]);
      else v[10].push_back(s[i]);
    }

    bool ok = true;
    for (int i = 0; i <= 10; ++i) {
      if (v[i].size() == 0) continue;
      if (unique(v[i].begin(), v[i].end()) - v[i].begin() > 1) {
        ok = false;
        break;
      }
    }

    if (ok) {
      ans = min(ans, __builtin_popcount(mask));
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  string s;
  cin >> s;
  int x = 0;
  for (auto i : s) {
    if (i == 'A') {
      x += 1;
    } else {
      x -= 1;
      if (x < 0) {
        cout << "NO\n";
        return;
      }
    }
  }
  if (s.front() == 'A' && s.back() == 'B') {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
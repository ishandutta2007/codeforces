#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint a1, K;
    cin >> a1 >> K;
    string s = to_string(a1);
    K--;
    while (K--) {
      bool zero = 0;
      lint mn = 10, mx = -1;
      for (auto i : s) {
        mn = min(mn, (lint) i - '0');
        mx = max(mx, (lint) i - '0');
        if (i == '0') zero = 1;
      }
      if (zero) {
        break;
      }
      a1 += mn * mx;
      s = to_string(a1);
    }
    cout << a1 << "\n";
  }
}
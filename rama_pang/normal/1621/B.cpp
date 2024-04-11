#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

void Main() {
  int n;
  cin >> n;
  int L = 1e9 + 100;
  int R = -1;
  int costL = 0;
  int costR = 0;
  int longest = -1;
  int costLong = 0;
  while (n--) {
    int l, r, c;
    cin >> l >> r >> c;

    if (longest < r - l) {
      longest = r - l;
      costLong = c;
    }
    if (longest == r - l) {
      costLong = min(costLong, c);
    }

    if (l < L) {
      L = l;
      costL = c;
    }
    if (l == L) {
      costL = min(costL, c);
    }
    if (R < r) {
      R = r;
      costR = c;
    }
    if (r == R) {
      costR = min(costR, c);
    }

    assert(R - L >= longest);
    if (R - L == longest) {
      cout << min(costL + costR, costLong) << '\n';
    } else {
      cout << costL + costR << '\n';
    }
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
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    // x + ak = y - bk -> y - x = (a + b)k
    int k = (y - x) / (a + b);
    if ((y - x) % (a + b) != 0) {
      cout << -1 << "\n";
    } else {
      cout << k << "\n";
    }

  }
}
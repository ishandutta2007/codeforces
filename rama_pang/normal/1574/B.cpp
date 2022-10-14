#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    if (m > a + b + c - 3) {
      cout << "NO\n";
    } else {
      int occ = max({a, b, c});
      int other = occ - (a + b + c + 1) / 2;
      other = max(other, 0);
      int add = 0;
      if ((a + b + c) % 2 == 0) {
        if (other > 0) {
          other -= 1;
          add += 1;
        }
      }
      add += 2 * other;
      if (m < add) {
        cout << "NO\n";
      } else {
        cout << "YES\n";
      }
    }
  }
  return 0;
}
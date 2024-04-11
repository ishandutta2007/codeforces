#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    lint a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <= b) {
      cout << b << "\n";
    } else {
      if (c <= d) {
        cout << -1 << "\n";
      } else {
        a -= b;
        lint rep = ceil(1.00 * a / (c - d));
        cout << b + rep * c << "\n";
      }
    }
  }
}
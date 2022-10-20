#include <bits/stdc++.h>

using namespace std;

long long a, b;

int main() {
  cin >> a >> b;
  if (a > b) {
    swap(a, b);
  }
  for (long long x = 1; x <= a; x++) {
    for (long long y = 1; y <= a; y++) {
      if (x * x + y * y == a * a) {
        long long f = x * b;
        if (f % a) {
          continue;
        }
        long long y2 = f / a;
        f = y * b;
        if (f % a) {
          continue;
        }
        long long x2 = f / a;
        if (x2 * x2 + y2 * y2 != b * b) {
          continue;
        }
        if (y2 == y) {
          continue;
        }
        cout << "YES\n";
        cout << "0 0\n";
        cout << x << " " << y << endl;
        cout << -x2 << " " << y2 << endl;
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
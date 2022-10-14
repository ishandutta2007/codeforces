#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, y, z;
    cin >> x >> y >> z;
    int mx = max({x, y, z});
    int cnt = 0;
    cnt += x == mx;
    cnt += y == mx;
    cnt += z == mx;
    if (cnt <= 1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if (x != mx) {
      cout << x << " " << 1 << " " << mx << "\n";
      continue;
    }
    if (y != mx) {
      cout << 1 << " " << mx << " " << y << "\n";
      continue;
    }
    if (z != mx) {
      cout << mx << " " << z << " " << 1 << "\n";
      continue;
    }
    cout << mx << " " << mx << " " << mx << "\n";
  }
  return 0;
}
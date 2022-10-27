#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int l = 1 << 30, r = 0, v1 = 0, v2 = 0, v = 2147483647;

    while (n--) {
      int x, y, z;
      cin >> x >> y >> z;
      if (l > x || r < y)
        v = 2147483647;
      if (x <= l && y >= r)
        v = min(v, z);
      if (l > x || (x == l && v1 > z))
        l = x, v1 = z;
      if (r < y || (y == r && v2 > z))
        r = y, v2 = z;
      cout << min(v1 + v2, v) << '\n';
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
using lint = long long;


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);


  int a, b;
  cin >> a >> b;
  int x = a - b;
  if (x < 0) {
    cout << 0 << "\n";
    return 0;
  }
  if (x == 0) {
    cout << "infinity\n";
    return 0;
  }
  int ans = 0;
  for (int f = 1; f * f <= x; f++) {
    if (a % f == b) {
      ans += 1;
    }
    if (a % (x / f) == b && f != x / f) {
      ans += 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
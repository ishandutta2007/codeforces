#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    int ans = max({
      x * b,
      (a - x - 1) * b,
      a * y,
      a * (b - y - 1)
    });
    cout << ans << "\n";
  }
  
}
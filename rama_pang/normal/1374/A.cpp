#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int x, y, n;
    cin >> x >> y >> n;
    int ans = n / x * x + y;
    while (ans > n) {
      ans -= x;
    }
    cout << ans << "\n";
  }
}
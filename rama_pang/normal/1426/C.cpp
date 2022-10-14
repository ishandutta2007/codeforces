#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    const auto Calc = [&](int x) {
      return (n - 1) / x + x - 1;
    };
    int hi = (int) sqrt(n);
    int ans = n - 1;
    for (int x = 1; x <= hi + 20; x++) {
      ans = min(ans, Calc(x));
    }
    cout << ans << "\n";
  }
  return 0;
}
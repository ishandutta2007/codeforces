#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    int ans = 2e9;
    for (int i = 1; i * i <= n; i++) {
      if (n % i == 0) {
        if (i <= k) {
          ans = min(ans, n / i);
        }
        if (n / i <= k) {
          ans = min(ans, i);
        }
      }
    }
    cout << ans << "\n";
  }
}
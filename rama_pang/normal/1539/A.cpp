#include <bits/stdc++.h>
using namespace std;

using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    lint N, X, T;
    cin >> N >> X >> T;
    lint ans = 0;
    lint L = T / X;
    // 0 + 1 + 2 + ... + L + L + L
    if (N <= L) {
      ans += 1ll * N * (N - 1) / 2;
    } else {
      ans += 1ll * L * (L - 1) / 2;
      ans += 1ll * L * (N - L);
    }
    cout << ans << '\n';
  }
  return 0;
}
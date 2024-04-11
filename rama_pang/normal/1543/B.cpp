#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint n;
  cin >> n;
  lint sum = 0;
  for (int i = 0; i < n; i++) {
    lint x;
    cin >> x;
    sum += x;
  }
  lint ans = 1e18;
  for (int i = 1; i <= n; i++) {
    lint d = sum / i;
    lint x = sum % i;
    __int128_t score = __int128_t(1) * (n - i) * i * d;
    score += 1ll * x * (n - x);
    if (score < ans) {
      ans = score;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
#include <cstdio>
#include <iostream>

using namespace std;

const int mod = 998244353;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, k, ans = 1;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
      ans = 1ll * ans * i % mod;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (i > n - k) {
        if (x > 0)
          ans = 0;
      } else if (x <= 0) {
        int tp = k + 1;
        if (x == -1)
          tp += i - 1;
        ans = 1ll * ans * tp % mod;
      }
    }
    cout << ans << '\n';
  }
}
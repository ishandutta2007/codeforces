#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, a[1005];
long long ans;
signed main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int l = 1; l < n; l += 2) {
    long long s = 0, gu = 1;
    for (int r = l + 1; r <= n; r += 2) {
      if (min(a[r] - s, (long long)a[l]) >= gu) ans += min(a[r] - s, (long long)a[l]) - gu + 1;
      s -= a[r], gu = max(gu, -s);
      if (a[l] < gu) continue;
      s += a[r + 1];
    }
  }
  cout << ans;
}
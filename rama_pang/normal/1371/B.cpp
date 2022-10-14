#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, r;
    cin >> n >> r;
    lint ans = 1ll * min(r, n - 1) * (min(r, n - 1) + 1) / 2 + (n <= r);
    cout << ans << "\n";
  }
}
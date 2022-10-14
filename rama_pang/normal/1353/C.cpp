#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    long long ans = 0;
    for (int sq = 1; sq <= n; sq += 2) {
      ans += 1ll * (sq / 2) * (1ll * sq * sq - 1ll * (sq - 2) * (sq - 2));
    }
    cout << ans << "\n";
  }
}
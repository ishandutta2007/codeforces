#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    if (n <= 2) {
      cout << 1 << "\n";
      continue;
    }
    n -= 2;
    int ans = 1;
    while (n > 0) {
      n -= x;
      ans++;
    }
    cout << ans << "\n";
  }
  return 0;
}
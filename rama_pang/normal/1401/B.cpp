#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int tt;
  cin >> tt;
  while (tt--) {
    int a0, a1, a2, b0, b1, b2;
    cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;
    int ans = min(a2, b1) * 2;
    tie(a2, b1) = make_pair(a2 - min(a2, b1), b1 - min(a2, b1));
    tie(a2, b2) = make_pair(a2 - min(a2, b2), b2 - min(a2, b2));
    tie(a0, b2) = make_pair(a0 - min(a0, b2), b2 - min(a0, b2));
    ans -= b2 * 2;
    cout << ans << "\n";
  }
  return 0;
}
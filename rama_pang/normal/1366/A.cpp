#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a < b) swap(a, b);
    int c = min({a - b, a / 2, b});
    int ans = c;
    a -= 2 * c;
    b -= c;
    int d = min(a / 3, b / 3);
    ans += 2 * d;
    a -= 3 * d;
    b -= 3 * d;
    if (a < b) swap(a, b);
    if (a >= 2 && b >= 1) ans++;
    cout << ans << "\n";
  }
}
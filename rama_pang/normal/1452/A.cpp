#include <bits/stdc++.h>
using namespace std;

void Main() {
  int x, y;
  cin >> x >> y;
  int ans = min(x, y);
  x -= ans;
  y -= ans;
  ans *= 2;
  if (max(x, y) > 0) {
    ans += 2 * max(x, y) - 1;
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
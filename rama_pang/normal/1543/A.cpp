#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  lint a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);
  if (a == b) {
    cout << "0 0\n";
    return;
  }
  
  // gcd(a + x, b + x) = gcd(a + x, b - a)
  lint diff = b - a;
  lint ans = min(a - a / diff * diff, (a + diff - 1) / diff * diff - a);
  cout << diff << ' ' << ans << '\n';
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
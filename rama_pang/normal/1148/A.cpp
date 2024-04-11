#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  lint a, b, ab;
  cin >> a >> b >> ab;
  lint ans = 2 * ab;
  if (a > b) swap(a, b);
  ans += 2 * a;
  b -= a;
  if (b > 0) {
    ans++;
  }
  cout << ans << "\n";
  return 0;
}
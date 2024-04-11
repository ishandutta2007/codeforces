#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n < 100) {
      cout << n % 10 << '\n';
      continue;
    }
    int ans = 1 << 30;
    while (n)
      ans = min(ans, n % 10), n /= 10;
    cout << ans << '\n';
  }
}
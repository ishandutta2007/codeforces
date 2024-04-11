#include <bits/stdc++.h>
using namespace std;

void Main() {
  int k;
  cin >> k;
  int ans = 0;
  while (k > 0) {
    ans++;
    while (ans % 3 == 0 || ans % 10 == 3) ans++;
    k--;
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
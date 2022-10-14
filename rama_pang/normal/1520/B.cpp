#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  int ans = 0;
  for (int d = 1; d <= 9; d++) {
    long long cur = d;
    while (cur <= n) {
      ans += 1;
      cur = cur * 10 + d;
    }
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
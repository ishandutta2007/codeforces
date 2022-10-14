#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, b, x, y;
  cin >> n >> b >> x >> y;
  long long ans = 0;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    if (last + x <= b) {
      last += x;
      ans += last;
    } else {
      last -= y;
      ans += last;
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
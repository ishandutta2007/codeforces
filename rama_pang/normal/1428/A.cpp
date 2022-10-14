#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  array<int, 4> a;
  for (int i = 0; i < 4; i++) {
    cin >> a[i];
  }
  int ans = abs(a[2] - a[0]) + abs(a[3] - a[1]);
  if (abs(a[2] - a[0]) > 0 && abs(a[3] - a[1]) > 0) {
    ans += 2;
  }
  cout << ans << "\n";

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
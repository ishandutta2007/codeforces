#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n;
  cin >> n;
  int ans = 0;
  int a = 0, b = 0;
  while (n--) {
    int r;
    cin >> r;
    if (a > b) swap(a, b);
    if (r == 1) {
      b += 1;
      ans += 1;
    } else if (r == 2) {
      a -= 1;
    } else {
      if (b >= 0) {
        b += 1;
        ans += 1;
      } else {
        a -= 1;
      }
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
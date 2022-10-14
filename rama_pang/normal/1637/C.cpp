#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int odd = 0;
  int one = 0;
  for (int i = 1; i < n - 1; i++) {
    odd += a[i] & 1;
    one += a[i] == 1;
  }
  int even = n - 2 - odd;
  if (even == 0) {
    // all is odd
    int all1 = 1;
    for (int i = 1; i < n - 1; i++) {
      all1 &= a[i] == 1;
    }
    if (n == 3 || all1) {
      cout << -1 << '\n';
    } else {
      // there exist a 3
      // -2 the 3
      // make some other odd +1
      // recurse
      lint ans = 0;
      for (int i = 1; i < n - 1; i++) {
        ans += (a[i] + 1) / 2;
      }
      cout << ans << '\n';
    }
  } else {
    lint ans = 0;
    for (int i = 1; i < n - 1; i++) {
      if (a[i] % 2 == 0) {
        ans += a[i] / 2;
      } else {
        ans += (a[i] + 1) / 2;
      }
    }
    cout << ans << '\n';
  }


  // if
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
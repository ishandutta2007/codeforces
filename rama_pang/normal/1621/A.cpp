#include <bits/stdc++.h>
using namespace std;

using lint = long long;
// #define int lint

void Main() {
  int n, k;
  cin >> n >> k;
  vector<string> ans(n, string(n, '.'));
  for (int i = 0; i < n; i += 2) {
    if (k > 0) {
      ans[i][i] = 'R';
      k--;
    }
  }
  if (k > 0) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i < n; i++) {
      cout << ans[i] << '\n';
    }
  }

}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
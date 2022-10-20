#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> x(n + 1, 0);
    vector<int> y(n + 1, 0);
    for (int i = 0; i < l; i++) {
      int u;
      cin >> u;
      x[u]++;
    }
    for (int i = 0; i < r; i++) {
      int u;
      cin >> u;
      y[u]++;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
      while (x[i] && y[i]) {
        x[i]--;
        y[i]--;
      }
    }
    int diff = abs(l - r);
    if (l > r) {
      for (int i = 1; i <= n && diff; i++) {
        while (x[i] > 1 && diff) {
          x[i] -= 2;
          diff -= 2;
          res++;
        }
      }
    } else {
      for (int i = 1; i <= n && diff; i++) {
        while (y[i] > 1 && diff) {
          y[i] -= 2;
          diff -= 2;
          res++;
        }
      }
    }
    int cnt_x = 0, cnt_y = 0;
    for (int i = 1; i <= n; i++) cnt_x += x[i];
    for (int i = 1; i <= n; i++) cnt_y += y[i];
    res += abs(cnt_x - cnt_y) / 2;
    res += (cnt_x + cnt_y) / 2;
    cout << res << '\n';
  }
  return 0;
}
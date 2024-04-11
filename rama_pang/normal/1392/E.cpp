#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<vector<long long>> mn(n, vector<long long>(n, 0));
  vector<vector<long long>> mx(n, vector<long long>(n, 0));
  vector<vector<long long>> a(n, vector<long long>(n, 0));
  long long cur = 0;
  for (int j = n - 2; j >= 0; j--) {
    long long add = 0;
    for (int i = 1; i < n; i++) {
      if (j == n - 1) {
        a[i][j] = 0;
        mx[i][j] = 0;
      } else {
        a[i][j] = cur - mn[i][j + 1] - add + 1;
        cur = max(cur, add + a[i][j] + mx[i][j + 1]);
        add += a[i][j];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      mx[i][j] = a[i][j];
      mn[i][j] = 1e18;
      if (i + 1 < n) {
        mx[i][j] = max(mx[i][j], a[i][j] + mx[i + 1][j]);
        mn[i][j] = min(mn[i][j], a[i][j] + mn[i + 1][j]);
      }
      if (j + 1 < n) {
        mx[i][j] = max(mx[i][j], a[i][j] + mx[i][j + 1]);
        mn[i][j] = min(mn[i][j], a[i][j] + mn[i][j + 1]);
      }
      if (i + 1 == n && j + 1 == n) {
        mn[i][j] = a[i][j];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  int q;
  cin >> q;
  while (q--) {
    long long k;
    cin >> k;
    vector<pair<int, int>> path;
    int x = 0, y = 0;
    for (int i = 0; i + 1 < 2 * n; i++) {
      if (x + 1 == n && y + 1 == n) {
        path.emplace_back(x, y);
      } else {
        path.emplace_back(x, y);
        k -= a[x][y];
        if (x + 1 < n && mn[x + 1][y] <= k && k <= mx[x + 1][y]) {
          x += 1;
        } else {
          y += 1;
        }
      }
    }
    assert(k == 0);
    for (auto p : path) {
      cout << p.first + 1 << " " << p.second + 1 << endl;
    }
    cout << endl;
  }
  return 0;
}
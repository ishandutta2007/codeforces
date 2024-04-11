#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

lint Power(lint n, lint x) {
  lint res = 1;
  for (; x > 0; x /= 2, n = 1ll * n * n % MOD) {
    if (x & 1) {
      res = 1ll * res * n % MOD;
    }
  }
  return res;
}

void Main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> l(n, vector<int>(n, 0));
  vector<vector<int>> r(n, vector<int>(n, 0));
  vector<vector<int>> d(n, vector<int>(n, 0));
  vector<vector<int>> u(n, vector<int>(n, 0));
  for (int dig = 0; dig < 10; dig++) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        l[i][j] = r[i][j] = d[i][j] = u[i][j] = -1e9;
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == dig + '0') {
          l[i][j] = 0;
          r[i][j] = 0;
          d[i][j] = 0;
          u[i][j] = 0;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < n; j++) {
        l[i][j] = max(l[i][j], l[i][j - 1] + 1);
      }
      for (int j = n - 2; j >= 0; j--) {
        r[i][j] = max(r[i][j], r[i][j + 1] + 1);
      }
    }
    for (int j = 0; j < n; j++) {
      for (int i = 1; i < n; i++) {
        u[i][j] = max(u[i][j], u[i - 1][j] + 1);
      }
      for (int i = n - 2; i >= 0; i--) {
        d[i][j] = max(d[i][j], d[i + 1][j] + 1);
      }
    }
    vector<int> left(n, -1e9);
    vector<int> right(n, -1e9);
    vector<int> down(n, -1e9);
    vector<int> up(n, -1e9);
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        left[j] = max(left[j], l[i][j]);
        if (j > 0) {
          left[j] = max(left[j], left[j - 1] + 1);
        }
      }
    }
    for (int j = n - 1; j >= 0; j--) {
      for (int i = 0; i < n; i++) {
        right[j] = max(right[j], r[i][j]);
        if (j + 1 < n) {
          right[j] = max(right[j], right[j + 1] + 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        up[i] = max(up[i], u[i][j]);
        if (i > 0) {
          up[i] = max(up[i], up[i - 1] + 1);
        }
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < n; j++) {
        down[i] = max(down[i], d[i][j]);
        if (i + 1 < n) {
          down[i] = max(down[i], down[i + 1] + 1);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (a[i][j] == dig + '0') {
          ans = max(ans, max({left[j], right[j], 0}) * max(i, n - i - 1));
          ans = max(ans, max({up[i], down[i], 0}) * max(j, n - j - 1));          
        } else {
          ans = max(ans, max({left[j], right[j], 0}) * max({d[i][j], u[i][j], 0}));
          ans = max(ans, max({l[i][j], r[i][j], 0}) * max({down[i], up[i], 0}));
        }
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
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
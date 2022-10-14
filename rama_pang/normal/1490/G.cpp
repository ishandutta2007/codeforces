#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;

  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    lint sum = accumulate(begin(a), end(a), 0ll);
    lint mx = 0;
    lint cur = 0;
    for (int i = 0; i < n; i++) {
      cur += a[i];
      mx = max(mx, cur);
    }
    const lint INF = 1e18;
    struct Data {
      lint mx = 0;
      lint sum = 0;
      Data operator+(const Data &o) {
        Data res;
        res.mx = max(mx, sum + o.mx);
        res.sum = sum + o.sum;
        res.mx = min(res.mx, INF);
        res.sum = min(res.sum, INF);
        return res;
      }
    };
    const int LOG = 60;
    vector<vector<Data>> dp(n, vector<Data>(LOG));
    for (int i = 0; i < n; i++) {
      dp[i][0].mx = max(0, a[i]);
      dp[i][0].sum = a[i];
    }
    for (int j = 1; j < LOG; j++) {
      for (int i = 0; i < n; i++) {
        dp[i][j] = dp[i][j - 1] + dp[(i + (1ll << (j - 1))) % n][j - 1];
      }
    }
    while (m--) {
      int x;
      cin >> x;
      if (sum <= 0 && mx < x) {
        cout << -1 << ' ';
        continue;
      }
      lint ans = 0;
      int i = 0;
      Data d;
      for (int j = LOG - 1; j >= 0; j--) {
        if ((d + dp[i][j]).mx < x) {
          d = d + dp[i][j];
          ans |= 1ll << j;
          i = (i + (1ll << j)) % n;
        }
      }
      if (d.mx < x) {
        ans += 1;
      }
      cout << ans - 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
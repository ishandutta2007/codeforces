#include <bits/stdc++.h>

using namespace std;

const int N = 510;

int n, t;
int a[N];
int f[N][N], g[N][N];
vector <int> val;
int b[N * N];
int d[N * 5];

void go() {
  b[0] = 0;
  for (int i = 1; i <= n * max(n, t); i++) {
    b[i] = 1e9;
  }
  int res = 0;
  for (int i = 1; i <= t; i++) {
    for (int j = 1; j <= n; j++) {
      int pos = upper_bound(b, b + n * max(n, t) + 1, a[j]) - b;
      res = max(res, pos);
      b[pos] = a[j];
    }
  }
  cout << res << endl;
}

void gof() {
  for (int it = 0; it < val.size(); it++) {
    b[0] = val[it];
    for (int i = 1; i <= n * n; i++) {
      b[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
      int res = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] < val[it]) {
          continue;
        }
        int pos = upper_bound(b, b + n * n + 1, a[j]) - b;
        res = max(res, pos);
        b[pos] = a[j];
      }
      f[it][i] = res;
    }
  }
}

void gog() {
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = -a[i];
  }
  for (int it = 0; it < val.size(); it++) {
    b[0] = -val[it];
    for (int i = 1; i <= n * n; i++) {
      b[i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
      int res = 0;
      for (int j = 1; j <= n; j++) {
        if (a[j] < -val[it]) {
          continue;
        }
        int pos = upper_bound(b, b + n * n + 1, a[j]) - b;
        res = max(res, pos);
        b[pos] = a[j];
      }
      g[it][i] = res;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> t;
  (time(0));
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[a[i]] ++;
    val.push_back(a[i]);
  }
  sort(val.begin(), val.end());
  val.resize(unique(val.begin(), val.end()) -val.begin());
  if (t <= n) {
    go();
    return 0;
  }
  t -= n;
  gof();
  gog();
  int res = 0;
  for (int i = 0; i < val.size(); i++) {
    int ans = 0;
    for (int j = 0; j <= n; j++) {
      ans = max(ans, g[i][j] + f[i][n - j]);
    }
    ans += t * d[val[i]];
    res = max(res, ans);
  }
  cout << res << endl;
  return 0;
}
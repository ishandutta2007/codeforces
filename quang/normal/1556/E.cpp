#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int LOG = 20;

int n, q;
int a[N], b[N];
long long s[N];

struct RMQ {
  long long min_val[LOG][N];
  long long max_val[LOG][N];

  void init() {
    for (int i = 1; i <= n; i++) {
      min_val[0][i] = max_val[0][i] = s[i];
    }
    for (int i = 1; i < LOG; i++) {
      for (int j = 1; j + (1 << i) - 1 <= n; j++) {
        min_val[i][j] = min(min_val[i - 1][j], min_val[i - 1][j + (1 << i - 1)]);
        max_val[i][j] = max(max_val[i - 1][j], max_val[i - 1][j + (1 << i - 1)]);
      }
    }
  }

  pair<long long, long long> Get(int l, int r) {
    int lg = log2(r - l + 1);
    long long foo = min(min_val[lg][l], min_val[lg][r - (1 << lg) + 1]);
    long long bar = max(max_val[lg][l], max_val[lg][r - (1 << lg) + 1]);
    return {foo, bar};
  }
} rmq;

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    s[i] = s[i - 1] + b[i] - a[i];
  }
  rmq.init();
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (s[l - 1] != s[r]) {
      cout << -1 << '\n';
      continue;
    }
    auto [u, v] = rmq.Get(l, r);
    if (u < s[r]) {
      cout << -1 << '\n';
    } else {
      cout << v - s[r] << '\n';
    }
  }
  return 0;
}
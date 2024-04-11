#include <bits/stdc++.h>
using namespace std;
 
const int N = 25;
const int M = 50005;
const int MOD = 998244353;

int n, m;
int d[N][M];
int fact[N];
int inv[N];

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

void init() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) {
    fact[i] = 1LL * fact[i - 1] * i % MOD;
    inv[i] = power(i, MOD - 2);
  }
}

int compute(vector<int> v) {
  sort(v.begin(), v.end(), greater<int>());
  int ret = 0;
  int cur = 1;
  for (int i = 0; i < v.size(); ++i) {
    ret = (1LL * cur * min(v[i], n - i) % MOD * inv[n - i] + ret) % MOD;
    cur = 1LL * cur * max(0, (n - i) - v[i]) % MOD * inv[n - i] % MOD;
    // cerr << v[i] << " " << ret << " " << cur << endl;
  }
  // cerr << ret << endl;
  return ret;
}

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &d[i][j]);
    }
  }

  int ans = 0;
  for (int j = 0; j < m; ++j) {
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
      v[i] = (n + 1) - d[i][j];
    }
    ans = (ans + compute(v)) % MOD;
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  init();
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
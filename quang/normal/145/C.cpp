#include <bits/stdc++.h>

using namespace std;

const int N = 100010, MOD = 1000000007, M = 2010;

int n, k;
long long dp[M][M], res;
long long f[N];
int st[N], top;
int ex;
pair<int, int> a[N];

bool check(int u) {
  while (u) {
    if (u % 10 != 4 && u % 10 != 7) {
      return 0;
    }
    u /= 10;
  }
  return 1;
}

long long qpow(long long u, int v) {
  long long res = 1;
  while (v) {
    if (v & 1) {
      res = res * u % MOD;
    }
    u = u * u % MOD;
    v >>= 1;
  }
  return res;
}

long long c(int n, int k) {
  if (k > n) {
    return 0;
  }
  if (k == 0 || k == n) {
    return 1;
  }
  long long res = f[k] * f[n - k] % MOD;
  res = qpow(res, MOD - 2) * f[n] % MOD;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    if (check(u)) {
      st[++top] = u;
    } else {
      ex++;
    }
  }
  n = 0;
  sort(st + 1, st + top + 1);
  for (int i = 1; i <= top; i++) {
    if (st[i] != st[i - 1]) {
      a[++n] = make_pair(st[i], 1);
    } else {
      a[n].second++;
    }
  }
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 1;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      dp[i][j] = (dp[i - 1][j - 1] * a[i].second + dp[i - 1][j]) % MOD;
    }
  }
  f[0] = 1;
  for (int i = 1; i < N; i++) {
    f[i] = f[i - 1] * i % MOD;
  }
  for (int i = 0; i <= k; i++) {
    res = (res + c(ex, k - i) * dp[n][i]) % MOD;
  }
  cout << res << endl;
  return 0;
}
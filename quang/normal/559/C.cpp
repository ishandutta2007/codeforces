#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int MOD = 1000000007;
typedef pair<pair<int, int>, int> pi;

int h, w;
int n, f[200010];
pair<int, int> a[N];
int dp[N];

int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

int qpow(int u, int v) {
  int res = 1;
  while (v) {
    if (v & 1) {
      res = 1ll * res * u % MOD;
    }
    u = 1ll * u * u % MOD;
    v >>= 1;
  }
  return res;
}

int C(int k, int n) {
  if (k == 0 || k == n) {
    return 1;
  }
  int res = f[n];
  int foo =(1ll * f[k] * f[n - k] % MOD);
  res = (1ll * res * qpow(foo, MOD - 2)) % MOD;
  return res;
}



int main() {
  ios_base::sync_with_stdio(0);
  cin >> h >> w >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  f[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    f[i] = (1ll * f[i - 1] * i) % MOD;
  }
  a[++n] = make_pair(h, w);
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    dp[i] = C(a[i].first - 1, a[i].first + a[i].second - 2);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[j].second > a[i].second) {
        continue;
      }
      int dis1 = a[i].first - a[j].first + 1;
      int dis2 = a[i].second - a[j].second + 1;
      int foo = 1ll * dp[j] * C(dis1 - 1, dis1 + dis2 - 2) % MOD;
      dp[i] = (1ll * dp[i] - foo + MOD) % MOD;
    }
  }
  cout << dp[n];
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 20, MOD = 1000000007;

int a[1 << N], n;

int add(int u, int v) {
  u += v;
  if (u >= MOD) {
    u -= MOD;
  }
  return u;
}

int qpow(int v) {
  int u = 2;
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

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int u;
    cin >> u;
    a[u]++;
  }
  for (int i = 0; i < 20; i++) {
    for (int j = (1 << 20) - 1; j; j--) {
      if (j & (1 << i)) {
        a[j ^ (1 << i)] = add(a[j ^ (1 << i)], a[j]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < (1 << 20); i++) {
    int t = __builtin_popcount(i);
    if (t & 1) {
      t = -1;
    } else {
      t = 1;
    }
    res = add(res, t * qpow(a[i]));
    res = add(res, MOD);
  }
  cout << res << endl;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
const int N = 100010;

int a[N], b[1000], n, k;
int x[1000];

int qpow(int u, int v) {
  int ans = 1;
  while (v) {
    if (v & 1) {
      ans = 1ll * ans * u % MOD;
    }
    u = 1ll * u * u % MOD;
    v >>= 1;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  int res = 0;
  for (int i = 1; i <= a[n]; i++) {
    k = 0;
    for (int j = 1; j * j <= i; j++) {
      if (i % j == 0) {
        b[++k] = j;
        if (j * j != i) {
          b[++k] = i / j;
        }
      }
    }
    sort(b + 1, b + k + 1);
    x[k + 1] = n + 1;
    for (int j = 1; j <= k; j++) {
      x[j] = lower_bound(a + 1, a + n + 1, b[j]) - a;
    }
    int ans = 1;
    for (int j = 1; j < k; j++) {
      ans = (1ll * ans * qpow(j, x[j + 1] - x[j])) % MOD;
    }
    int foo = qpow(k, x[k + 1] - x[k]);
    foo = (1ll * foo - qpow(k - 1, x[k + 1] - x[k]) + MOD) % MOD;
    ans = 1ll * ans * foo % MOD;
    res = res + ans;
    if (res >= MOD) {
      res -= MOD;
    }
  }
  cout << res << endl;
  return 0;
}
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200005, mod = 998244353;
int n, k, fac[N], ifac[N];
int p[N], tot, mu[N], sum[N];
bool np[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }
int sub(int x, int y) { return x < y ? x + mod - y : x - y; }

int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1)
      tp = 1ll * tp * a % mod;
    a = 1ll * a * a % mod, n >>= 1;
  }
  return tp;
}

void prep(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i])
      p[++tot] = i, mu[i] = -1;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = 1;
      if (i % p[j] == 0)
        break;
      mu[i * p[j]] = -mu[i];
    }
  }

  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = 1ll * fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], mod - 2);
  for (int i = n - 1; ~i; i--)
    ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}

int query(int n, int k) {
  static int v[N];
  k = min(n, k);
  int ans = sum[k - 1];
  for (int i = 2; i <= k; i++) {
    if (!np[i])
      v[i] = power(i, n);
    ans = (ans + 1ll * v[i] * ifac[i] % mod * sum[k - i]) % mod;
    for (int j = 1; j <= tot && i * p[j] <= k; j++) {
      v[i * p[j]] = 1ll * v[i] * v[p[j]] % mod;
      if (i % p[j] == 0)
        break;
    }
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> k, prep(n);
  if (k == 1) {
    cout << 1;
    return 0;
  }
  sum[0] = 1;
  for (int i = 1; i < k; i++)
    if (i & 1)
      sum[i] = sub(sum[i - 1], ifac[i]);
    else
      sum[i] = add(sum[i - 1], ifac[i]);

  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (mu[i] && 1ll * i * p[tot] > n && i % p[tot]) {
      if (mu[i] == 1)
        ans = sub(ans, 1);
      else
        ans = add(ans, 1);
    }
  for (int i = 1; i <= n; i++)
    if (mu[i]) {
      int m = (n + i - 1) / i;
      if (mu[i] == 1)
        ans = add(ans, query(m, k));
      else
        ans = sub(ans, query(m, k));
    }
  cout << ans;
}
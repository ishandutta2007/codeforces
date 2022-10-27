#include <cstdio>
#include <iostream>

using namespace std;

const int N = 10000005, mod = 998244353;
int pw0[65536], pw1[65536];
int q[N], qfac[N], iqfac[N];

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

int pw2(int n) { return 1ll * pw0[n & 65535] * pw1[n >> 16] % mod; }

int qc(int n, int m) { return 1ll * qfac[n] * iqfac[m] % mod * iqfac[n - m] % mod; }

void init() {
  int n = 10000000;
  pw0[0] = 1;
  for (int i = 1; i < 65536; i++)
    pw0[i] = add(pw0[i - 1], pw0[i - 1]);

  pw1[0] = 1, pw1[1] = add(pw0[65535], pw0[65535]);
  for (int i = 2; i < 65536; i++)
    pw1[i] = 1ll * pw1[i - 1] * pw1[1] % mod;

  q[0] = qfac[0] = 1;
  for (int i = 1, x = 1; i <= n; i++) {
    x = add(x, x);
    q[i] = sub(x, 1);
    qfac[i] = 1ll * qfac[i - 1] * q[i] % mod;
  }

  iqfac[n] = power(qfac[n], mod - 2);
  for (int i = n - 1; ~i; i--)
    iqfac[i] = 1ll * iqfac[i + 1] * q[i + 1] % mod;
}

int calc(int k, int n) {
  if (n > k)
    return 0;
  return 1ll * qc(k, n) * pw2(1ll * n * (n - 1) / 2 % (mod - 1)) % mod;
}

int solve() {
  int n, k, x;
  cin >> n >> k >> x;
  if (!x)
    return 1ll * qfac[n] * calc(k, n) % mod;

  int ans = 0, tp = pw2(k);
  for (int i = 0, v = 1; i <= n && i < k; i++) {
    int x = 1ll * sub(tp, pw2(i)) * calc(k, i) % mod;
    ans = (ans + 1ll * x * v) % mod;
    v = 1ll * v * sub(pw2(n - i), 1) % mod;
  }
  return 1ll * ans * power(pw2(k) - 1, mod - 2) % mod;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  init();

  int t;
  cin >> t;
  while (t--)
    cout << solve() << '\n';
}
#include <bits/stdc++.h>
using namespace std;
const int N = 14, mod = 1e9 + 7;
int n, a[N], iv[2000005], ans;
int p[N][1 << N], f[1 << N];
inline int sub(int x, int y) { return x < y ? x + mod - y : x - y; }
inline int query(int s, int t) {
  int ans = 1;
  for (int i = 0; i < n; i++)
    if (s >> i & 1) ans = 1ll * ans * p[i][t] % mod;
  return ans;
}
int main() {
  cin >> n;
  iv[1] = 1;
  for (int i = 2; i <= 2000000; i++) {
    int j = mod / i + 1;
    iv[i] = 1ll * iv[i * j - mod] * j % mod;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++)
    for (int s = 0; s < (1 << n); s++) {
      p[i][s] = 1;
      for (int j = 0; j < n; j++)
        if (s >> j & 1) p[i][s] = 1ll * p[i][s] * a[i] % mod * iv[a[i] + a[j]] % mod;
    }
  f[0] = 1;
  for (int s = 1; s < (1 << n); s++) {
    f[s] = 1;
    for (int t = (s - 1) & s; t; t = (t - 1) & s) {
      f[s] = sub(f[s], 1ll * f[t] * query(t, s ^ t) % mod);
    }
    ans = (ans + 1ll * __builtin_popcount(s) * f[s] % mod * query(s, ((1 << n) - 1) ^ s)) % mod;
  }
  cout << ans;
}
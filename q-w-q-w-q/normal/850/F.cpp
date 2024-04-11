// LUOGU_RID: 90395399
#include <iostream>
#include <cstdio>

using namespace std;

const int N = 1000005, mod = 1e9 + 7;
int n, a[N], s, mx, f[N];
int iv[N];

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

void prep(int s, int n) {
  iv[0] = s;
  for (int i = 1; i <= n; i++)
    iv[i] = 1ll * iv[i - 1] * (s - i) % mod;
  iv[n] = power(iv[n], mod - 2);
  for (int i = n; i != -1; i--) {
    int x = iv[i];
    if (i)
      x = 1ll * x * iv[i - 1] % mod, iv[i - 1] = 1ll * iv[i] * (s - i) % mod;
    iv[i] = x;
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], mx = max(mx, a[i]), s = add(s, a[i]);

  prep(s, mx - 1);

  for (int i = 1, d = 1ll * (s - 1) * iv[0] % mod; i <= mx; d = sub(d, iv[i++]))
    f[i] = add(f[i - 1], d);

  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = add(ans, f[a[i]]);
  cout << 1ll * ans * (s - 1) % mod << endl;
}
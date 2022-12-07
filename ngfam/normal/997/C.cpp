#include<bits/stdc++.h>
#define int long long

using namespace std;

const int MAXN = 2e6 + 5;
const int mod = 998244353;

int mul(int x, int y) {
  return x * y % mod;
}

void add(int &x, int y) {
  x += y;
  if(x >= mod) x -= mod;
  if(x < 0) x += mod;
}

int fpow(int x, int y) {
  y = (y + mod - 1) % (mod - 1);
  int risan = 1;
  for(; y > 0; y >>= 1, x = mul(x, x)) {
    if(y & 1) risan = mul(risan, x);
  }
  return risan;
}

int fact[MAXN], inv[MAXN];

int comb(int n, int i) {
  if(i > n) return 1;
  return mul(fact[n], mul(inv[i], inv[n - i]));
}

main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  fact[0] = inv[0] = 1;
  for(int i = 1; i < MAXN; ++i) {
    fact[i] = mul(fact[i - 1], i);
    inv[i] = fpow(fact[i], -1);
  }

  int n; cin >> n;

  int ans = fpow(3, n * n);

  for(int a = 1; a <= n; ++a) {
    int first = mul(comb(n, a), fpow(3, (n - a) * n + 1));
    int p = fpow(3, a - n);
    int risan = fpow(1 - p + mod, n);
    add(risan, -1);
    risan = mul(risan, first);
    if(a % 2) add(ans, -risan);
    else add(ans, risan);
  }

  for(int i = 1; i <= n; ++i) {
    int calc = mul(fpow(3, i), 2);
    calc = mul(calc, comb(n, i));
    calc = mul(calc, fpow(3, n * (n - i)));
    if(i % 2 == 1) calc *= -1;
    add(ans, calc);
  }

  cout << (fpow(3, n * n) - ans + mod) % mod << endl;

  return 0;
}
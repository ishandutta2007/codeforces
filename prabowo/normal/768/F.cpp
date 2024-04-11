#include <bits/stdc++.h>
using namespace std;

#define MAXN 200005
#define MOD 1000000007

int fact[MAXN], inv[MAXN];

int power(int carry, int n) {
  int ret = 1;
  
  while (n > 0) {
    if (n & 1) ret = 1LL * ret * carry % MOD;
    carry = 1LL * carry * carry % MOD;
    n >>= 1;
  }
  
  return ret;
}

int C(long long n, int k) {
  if (n < 0 || k > n) return 0;
  else return 1LL * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
}

int main() {
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = 1LL * i * fact[i - 1] % MOD;
    inv[i] = power(fact[i], MOD - 2);
  }
  
  long long n, m, h, p = 0, q = 0;
  cin >> n >> m >> h;

  if (n == 0) {
    cout << (h == 0) << endl;
    return 0;
  }  

  if (m == 0) {
    cout << 1 << endl;
    return 0;
  }
  
  for (int i = 1; i <= n; i++) {
    p += 1LL * (2LL * C(m - h*i - 1, i - 1) + C(m - h*(i-1) - 1, i-2) + C(m - h*(i+1) - 1, i)) * C(n - 1, i - 1) % MOD;
    p %= MOD;
    q += 1LL * C(m + 1, i) * C(n-1, i-1) % MOD;
    q %= MOD;
    
  }
  
  cout << 1LL * p * power(q, MOD - 2) % MOD << endl;
  
  return 0;
}
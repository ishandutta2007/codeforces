#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint MOD = 1e9 + 7;

template<typename T>
void Add(T &a, lint b) {
  a += b;
  a -= (a >= MOD) * MOD;
}

lint Power(lint x, lint y) {
  lint res = 1;
  for (; y; y /= 2, x = 1ll * x * x % MOD) {
    if (y & 1) {
      res = 1ll * res * x % MOD;
    }
  }
  return res;
} 

void Main() {
  int n;
  int m = 3;
  int k = 2;
  cin >> n >> m >> k;
  vector<int> cnt(n);
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    cnt[--a]++;
  }
  vector<lint> fact(n + 1);
  vector<lint> inv(n + 1);
  fact[0] = inv[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv[i] = Power(fact[i], MOD - 2);
  }
  const auto C = [&](lint n, lint k) {
    if (k < 0 || k > n) return 0ll;
    return 1ll * fact[n] * inv[k] % MOD * inv[n - k] % MOD;
  };
  lint ans = 0;
  lint oth = 0;
  for (int i = 0; i < n; i++) {
    ans += C(cnt[i] + oth, m);
    ans -= C(oth, m);
    ans %= MOD;
    oth += cnt[i];
    if (i - k >= 0) {
      oth -= cnt[i - k];
    }
  }
  ans %= MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}
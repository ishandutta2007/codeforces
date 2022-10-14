#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const int MAXN = 500005;
const int MOD = 998244353;

int fact[MAXN];
int inv[MAXN];

int Power(int x, int y) {
  if (y == 0) return 1;
  int res = Power(x, y / 2);
  res = 1ll * res * res % MOD;
  if (y & 1) res = 1ll * res * x % MOD;
  return res;
}

int Choose(int n, int r) {
  if (r < 0 || r > n) return 0;
  return 1ll * fact[n] * inv[r] % MOD * inv[n - r] % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N, K;
  cin >> N >> K;
  if (N < K) {
    cout << 0 << "\n";
    return 0;
  }  
  // N >= K
  fact[0] = inv[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    fact[i] = 1ll * i * fact[i - 1] % MOD;
    inv[i] = Power(fact[i], MOD - 2);
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int divisible = N / i;
    ans = (ans + Choose(divisible - 1, K - 1)) % MOD;
  }
  cout << ans << "\n";
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  const int MOD = 998244353;
  const int MAX = 3000000;
  vector<int> inv(MAX);
  inv[1] = 1;
  for (int i = 2; i < MAX; i++) {
    inv[i] = (MOD - (1ll * (MOD / i) * (inv[MOD % i]) % MOD)) % MOD;
  }
  
  int each_iter = (1ll * n * inv[m + 1] % MOD + 1) % MOD;
  vector<int> get_new(n + 1);
  get_new[1] = m + 1;
  for (int i = 2; i <= n; i++) {
    get_new[i] = get_new[i - 1];
    get_new[i] += 1ll * m * inv[i] % MOD;
    if (get_new[i] >= MOD) get_new[i] -= MOD;
  }

  int ans = 1ll * get_new[n] * each_iter % MOD;
  cout << ans << "\n";
  return 0;
}
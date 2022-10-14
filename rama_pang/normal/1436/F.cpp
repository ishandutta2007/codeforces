#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // sum(S) * sum(S) * (|S| - 1)
  // 
  // Contribution a * a from (a + b + ...) * (a + b + ...) + (|S| - 1)
  // = a * a * (0 * C(N - 1, 0) + 1 * C(N - 1, 1) + ... + C(N - 1, N - 1) * (N - 1))
  // = a * a * 2^(N - 2) * (N - 1)
  // 
  // Contribution a * b from (a + b + ...) * (a + b + ...) + (|S| - 1)
  // = 2 * a * b * (1 * C(N - 2, 0) + 2 * C(N - 2, 1) + ... + C(N - 2, N - 2) * (N - 1))
  // = 2 * a * b * (2^(N - 3) * (N - 2) + 2^(N - 2))
  // = 2 * a * b * 2^(N - 3) * N

  const int MAX = 1e5 + 5;

  int m;
  cin >> m;

  vector<__int128_t> sum(MAX);
  vector<__int128_t> sum2(MAX);
  vector<__int128_t> freq(MAX);

  const int MOD = 998244353;
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    int f;
    cin >> f;
    freq[x] = f;
    sum[x] += 1ll * x * freq[x] % MOD;
    sum2[x] += 1ll * x * x % MOD * freq[x] % MOD;
  }

  for (int i = 1; i < MAX; i++) {
    for (int j = i + i; j < MAX; j += i) {
      freq[i] += freq[j];
      sum[i] += sum[j];
      sum[i] %= MOD;
      sum2[i] += sum2[j];
      sum2[i] %= MOD;
    }
  }

  const auto Power = [&](int a, long long x) {
    int res = 1;
    int mul = a;
    while (x) {
      if (x & 1) {
        res = 1ll * mul * res % MOD;
      }
      mul = 1ll * mul * mul % MOD;
      x /= 2;
    }
    return res;
  };

  vector<int> dp(MAX);
  for (int i = MAX - 1; i > 0; i--) {
    dp[i] = 0;
    if (freq[i] >= 2) {
      // Contribution a * a
      dp[i] += 1ll * sum2[i] * Power(2, freq[i] - 2) % MOD * (freq[i] % MOD - 1) % MOD;
      dp[i] %= MOD;
      // Contribution a * b
      dp[i] += 1ll * (1ll * sum[i] * sum[i] % MOD - sum2[i]) % MOD * 
               (freq[i] == 2 ? 1 : (1ll * Power(2, freq[i] - 3) * (freq[i] % MOD) % MOD)) % MOD;
      dp[i] %= MOD;
    }
    for (int j = i + i; j < MAX; j += i) {
      dp[i] -= dp[j];
      dp[i] %= MOD;
    }
    if (dp[i] < 0) {
      dp[i] += MOD;
    }
  }

  cout << dp[1] << "\n";
  return 0;
}
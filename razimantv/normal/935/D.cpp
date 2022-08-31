#include <iostream>
#include <vector>

const long long MOD = 1000000007;

long long modpow(long long x, long long y, long long p) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = (ret * x) % p;
    x = (x * x) % p;
    y >>= 1;
  }
  return ret;
}

long long inv(long long x, long long p) { return modpow(x, p - 2, p); }

int main() {
  int N, M;
  std::cin >> N >> M;
  long long MC2 = ((M * (long long)(M - 1)) / 2) % MOD;

  std::vector<int> A(N), B(N);
  for (int i = 0; i < N; ++i) {
    std::cin >> A[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> B[i];
  }

  // DP[i] stores number of ways to fill blanks in iN such that A > B
  // if prefix is > or =
  std::vector<std::pair<long long, long long>> DP(N + 1);
  DP[N] = {1, 0};

  long long zeros = 0;
  for (int i = N - 1; i >= 0; --i) {
    zeros += (A[i] == 0) + (B[i] == 0);

    DP[i].first = DP[i + 1].first;
    if (A[i] == 0) DP[i].first = (DP[i].first * M) % MOD;
    if (B[i] == 0) DP[i].first = (DP[i].first * M) % MOD;

    if (A[i] == 0 and B[i] == 0) {
      DP[i].second = (MC2 * DP[i + 1].first + M * DP[i + 1].second) % MOD;
    } else if (A[i] == 0) {
      DP[i].second = ((M - B[i]) * DP[i + 1].first + DP[i + 1].second) % MOD;
    } else if (B[i] == 0) {
      DP[i].second = ((A[i] - 1) * DP[i + 1].first + DP[i + 1].second) % MOD;
    } else if (A[i] > B[i]) {
      DP[i].second = DP[i + 1].first;
    } else if (A[i] == B[i]) {
      DP[i].second = DP[i + 1].second;
    } else {
      DP[i].second = 0;
    }
  }

  long long ans = (DP[0].second * modpow(inv(M, MOD), zeros, MOD)) % MOD;
  std::cout << ans << std::endl;
  return 0;
}
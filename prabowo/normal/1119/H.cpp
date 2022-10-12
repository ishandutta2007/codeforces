#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;

// K-tuple
const int K = 3;

int n, k;
int x[K];

void fwht(int n, vector<int> &data, bool inverse=false) {
  for (int len = 1; 2 * len <= n; len <<= 1) {
    for (int i = 0; i < n; i += 2 * len) {
      for (int j = 0; j < len; j++) {
        int a = data[i + j];
        int b = data[i + j + len];

        data[i + j] = (a + b) % MOD;
        data[i + j + len] = (a - b) % MOD;
      }
    }
  }
}

int power(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }

  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < K; ++i) scanf("%d", &x[i]);

  vector<int> v[1 << K];
  for (int i = 0; i < 1 << K; ++i) v[i] = vector<int>(1 << k);

  for (int i = 0; i < n; ++i) {
    int a[K];
    for (int j = 0; j < K; ++j) scanf("%d", &a[j]);

    for (int mask = 0; mask < 1 << K; ++mask) {
      int sum = 0;
      for (int j = 0; j < K; ++j) {
        if (mask >> j & 1) {
          sum ^= a[j];
        }
      }

      v[mask][sum] += 1;
    }
  }

  for (int i = 0; i < 1 << K; ++i) fwht(1 << k, v[i]);

  vector<int> ans(1 << k, 1);

  vector<int> sum(1 << K);
  for (int mask = 0; mask < 1 << K; ++mask) {
    for (int i = 0; i < K; ++i) {
      if (mask >> i & 1) {
        sum[mask] = (sum[mask] - x[i]) % MOD;
      } else {
        sum[mask] = (sum[mask] + x[i]) % MOD;
      }
    }

    if (sum[mask] < 0) sum[mask] += MOD;
  }

  int inv = power(1 << K, MOD-2);
  for (int i = 0; i < 1 << k; ++i) {
    vector<int> cnt(1 << K);
    for (int mask = 0; mask < 1 << K; ++mask) {
      cnt[mask] = v[mask][i];
    }
    fwht(1 << K, cnt);

    for (int mask = 0; mask < 1 << K; ++mask) {
      cnt[mask] = 1LL * cnt[mask] * inv % MOD;
      if (cnt[mask] < 0) cnt[mask] += MOD;

      ans[i] = 1LL * ans[i] * power(sum[mask], cnt[mask]) % MOD;
    }
  }

  fwht(1 << k, ans, true);

  inv = power(1 << k, MOD-2);
  for (int i = 0; i < 1 << k; ++i) {
    if (ans[i] < 0) ans[i] += MOD;
    ans[i] = 1LL * ans[i] * inv % MOD;
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}

// K = 2

// a = x0 + x1
// b = -x0 + x1
// c = x0 - x1
// d - -x0 - x1

// v[0] = a + b + c + d = n
// v[1] = a - b + c - d
// v[2] = a + b - c - d
// v[3] = a - b - c + d

// a = (v[0] + v[1] + v[2] + v[3]) // 4
//
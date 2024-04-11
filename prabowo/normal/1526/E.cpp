#include <cstdio>

const int N = 200005;
const int MOD = 998244353;

int n, k;
int a[N];
int rank[N];

int inv(int x) {
  int ret = 1;
  for (int y = MOD - 2; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    rank[a[i]] = i;
  }
  rank[n] = -1;

  int res = 0;
  for (int i = 0; i < n - 1; ++i) {
    if (rank[a[i] + 1] > rank[a[i + 1] + 1]) ++res;
  }

  // C(n + k - 1 - res, k - 1 - res)
  if (n + k - 1 - res < k - 1 - res || k - 1 - res < 0) return 0 * printf("0\n");
  int num = 1, den = 1;
  for (int i = 0; i < k - 1 - res; ++i) {
    num = 1LL * num * (n + k - 1 - res - i) % MOD;
    den = 1LL * den * (i + 1) % MOD;
  }

  int ans = 1LL * num * inv(den) % MOD;
  printf("%d\n", ans);
  return 0;
}
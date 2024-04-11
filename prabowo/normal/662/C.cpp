#include <cstdio>

const int N = 20;
const int M = 100005;

void fwht(int n, long long a[]) {
  for (int len = 1; len < n; len <<= 1) {
    for (int i = 0; i < n; i += len << 1) {
      for (int j = 0; j < len; ++j) {
        long long u = a[i + j], v = a[i + j + len];
        a[i + j] = u + v;
        a[i + j + len] = u - v;
      }
    }
  }
}

int n, m;
char s[N][M];

long long cnt[1 << N], val[1 << N];

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%s", s[i]);

  for (int i = 0; i < m; ++i) {
    int mask = 0;
    for (int j = 0; j < n; ++j) mask |= (s[j][i] - '0') << j;
    ++cnt[mask];
  }
  for (int i = 0; i < 1 << n; ++i) {
    val[i] = __builtin_popcount(i);
    val[i] = n - val[i] < val[i] ? n - val[i] : val[i];
  }

  fwht(1 << n, cnt); fwht(1 << n, val);
  for (int i = 0; i < 1 << n; ++i) val[i] *= cnt[i];
  fwht(1 << n, val);

  long long ans = 1LL << 60;
  for (int i = 0; i < 1 << n; ++i) {
    if (val[i] < ans) ans = val[i];
  }
  ans >>= n;
  printf("%lld\n", ans);
  return 0;
}
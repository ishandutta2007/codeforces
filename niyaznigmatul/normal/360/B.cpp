#include <cstdio>

const int N = 123456;

int a[N], dp[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  long long l = -1;
  long long r = 1LL << 33;
  while (l < r - 1) {
    long long mid = (l + r) >> 1;
    for (int i = 0; i < n; i++) {
      dp[i] = i;
      for (int j = 0; j < i; j++) {
        long long dif = a[i] - a[j];
        if (dif < 0) dif = -dif;
        if (dif <= mid * (i - j)) {
          int val = dp[j] + i - j - 1;
          if (dp[i] > val) dp[i] = val;
        }
      }
    }
    int cur = n + 1;
    for (int i = 0; i < n; i++) {
      if (cur > dp[i] + n - i - 1) cur = dp[i] + n - i - 1;
    }
    if (cur <= k) r = mid; else l = mid;
  }
  printf("%I64d\n", r);
}
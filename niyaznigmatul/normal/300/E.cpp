#include <cstdio>
#include <algorithm>

int ni() {
  int c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int x = 0;
  while (c >= '0' && c <= '9') {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}

const int MAXN = 11111111;
int np[MAXN];
long long cnt[MAXN];
int a[MAXN];

int main() {
  int n = ni();
  for (int i = 0; i < n; i++) {
    int x = ni();
    a[x]++;
  }
  for (int i = MAXN - 2; i >= 2; i--) {
    a[i] += a[i + 1];
  }
  for (int i = 2; i < MAXN; i++) {
    if (np[i]) continue;
    for (int j = i; j < MAXN; j += i) {
      np[j] = i;
      int x = j;
      int cn = 0;
      while (x % i == 0) x /= i, ++cn;
      cnt[i] += a[j] * cn;
    }
  }
  long long ans = 1;
  for (int i = 2; i < MAXN; i++) {
    if (np[i] != i) continue;
    long long cc = cnt[i];
    if (cc == 0) continue;
    long long l = -1;
    long long r = 1LL << 60;
    while (l < r - 1) {
      long long mid = (l + r) >> 1;
      long long cn = 0;
      long long cur = mid;
      while (cur >= i) {
        cur /= i;
        cn += cur;
        if (cn >= cc) break;
      }
      if (cn >= cc) r = mid; else l = mid;
    }
    if (ans < r) ans = r;
  }
  printf("%I64d\n", ans);
}
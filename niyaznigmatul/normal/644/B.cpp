#include <cstdio>

int const N = 1234567;
int t[N], d[N];
int q[N];

long long ans[N];

int main() {
  int n, b;
  scanf("%d%d", &n, &b);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", t + i, d + i);
    ans[i] = -1;
  }
  int cur = 0;
  int head = 0;
  int tail = 0;
  long long ct = 0;
  while (head < tail || cur < n) {
    if (cur < n && (ct > t[cur] || head == tail)) {
      if (tail - head < b) {
        q[tail++] = cur;
      }
      ++cur;
      continue;
    }
    if (head < tail) {
      int v = q[head++];
      if (ct < t[v]) {
        ct = t[v];
      }
      ct += d[v];
      ans[v] = ct;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%lld", ans[i]);
  }
  puts("");
}
#include <cstdio>
#include <algorithm>

int get(int c, int v, int m, int d) {
  if (m < v || v + d * c < m) return -100000;
  int ret = 0;
  for (int i = 0; i < c; i++) {
    ret += v;
    v += d;
    if (v > m) v = m;
  }
  return ret;
}

int main() {
  int v1, v2, t, d;
  scanf("%d%d%d%d", &v1, &v2, &t, &d);
  int ans = 0;
  for (int i = 0; i < t; i++) {
    int m = i * d + v1;
    int cur = get(i, v1, m, d) + get(t - i - 1, v2, m, d) + m;
    if (ans < cur) ans = cur;
  }
  std::swap(v1, v2);
  for (int i = 0; i < t; i++) {
    int m = i * d + v1;
    int cur = get(i, v1, m, d) + get(t - i - 1, v2, m, d) + m;
    if (ans < cur) ans = cur;
  }
  printf("%d\n", ans);
}
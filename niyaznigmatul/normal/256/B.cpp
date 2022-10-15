#include <cstdio>
#include <algorithm>

long long get(int x, int y, int c) {
  --c;
  if (x <= 0 || y <= 0 || c <= 0) return 0;
  if (x > y) std::swap(x, y);
  int first = x - c + 1;
  int from = std::max(1, first);
  int cur = from - first + 1;
  long long all = 0;
  while (from <= x) {
    all += std::min(y, cur);
    ++cur;
    from++;
    if (all > 1 << 30) return all;
  }
  return all;
}

int main() {
  int n, x, y, c;
  scanf("%d%d%d%d", &n, &x, &y, &c);
  int l = -1;
  int r = c + 5;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    long long all = 1LL + std::min(x - 1, mid) + std::min(y - 1, mid) + std::min(n - x, mid) + std::min(n - y, mid) + 
      get(x - 1, y - 1, mid) + get(n - x, y - 1, mid) + get(n - x, n - y, mid) + get(x - 1, n - y, mid);
    if (all >= c) r = mid; else l = mid;
  }
  printf("%d\n", r);
}
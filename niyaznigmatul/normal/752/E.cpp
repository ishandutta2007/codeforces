#include <cstdio>
#include <unordered_map>
#include <cassert>
using namespace std;

unordered_map<int, int> d;

// int get2(int n, int x) {
//   if (n < x) return 0;
//   if (n / 2 < x) return 1;
//   if (d.find(n) != d.end()) return d[n];
//   return d[n] = get2(n / 2, x) + get2((n + 1) / 2, x);
// }

int get(int n, int x) {
  if (n < x) return 0;
  int q = 0;
  while (((x << q) << 1) <= n) {
    ++q;
  }
  int ans = 1 << q;
  int ans2 = (1 << (q + 1)) - ((x << (q + 1)) - n);
  return std::max(ans, ans2);
}

int a[1234567];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  int l = 0;
  int r = 1 << 24;
  while (l < r - 1) {
    int mid = (l + r) >> 1;
    long long count = 0;
    for (int i = 0; i < n; i++) {
      count += get(a[i], mid);
    }
    if (count >= k) {
      l = mid;
    } else {
      r = mid;
    }
  }
  printf("%d\n", l == 0 ? -1 : l);
}
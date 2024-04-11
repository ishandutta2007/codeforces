#include <cstdio>
#include <cassert>

int g[1111111], has[1111111], gg[1111111][5];

int main() {
  int first = 1;
  for (int i = 1; i <= 1000000; i++) {
    while (first * first * first * first < i) ++first;
    for (int j = first; j * j <= i && j < i; j++) {
      has[g[j]] = i;
    }
    for (int j = 0;; j++) {
      if (has[j] != i) {
        g[i] = j;
        break;
      }
    }
    gg[i][g[i]]++;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 1; j <= 1000000; j++) gg[j][i] += gg[j - 1][i];
  }
  int n;
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%I64d", &x);
    long long l = 0;
    long long r = 1000;
    while (l < r - 1) {
      long long mid = (l + r) >> 1;
      if (mid * mid * mid * mid >= x) r = mid; else l = mid;
    }
    int left = r;
    l = 0;
    r = 1000000;
    while (l < r - 1) {
      long long mid = (l + r) >> 1;
      if (mid * mid <= x) l = mid; else r = mid;
    }
    int right = l;
    if (right == x) right--;
    if (left > right) {
      continue;
    }
    int found = -1;
    for (int q = 0; q < 5; q++) {
      if (gg[right][q] - gg[left - 1][q] == 0) {
        found = q;
        break;
      }
    }
    assert(found >= 0);
    ans ^= found;
  }
  puts(ans == 0 ? "Rublo" : "Furlo");
}
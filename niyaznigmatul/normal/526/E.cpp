#include <bits/stdc++.h>

long long get() {
  int c = getchar();
  while (c <= 32) c = getchar();
  long long ret = 0;
  while (c > 32) {
    ret = ret * 10 + c - '0';
    c = getchar();
  } 
  return ret;
}

int const N = 2333444;
int a[N], go[N];

int main() {
  int n = get();
  int q = get();
  long long allsum = 0;
  for (int i = 0; i < n; i++) {
    a[i + n] = a[i] = get();
    allsum += a[i];
  }
  for (int tt = 0; tt < q; tt++) {
    long long b = get();
    if (b >= allsum) {
      puts("1");
      continue;
    }
    long long s = 0;
    int left = -1;
    int right = 2 * n;
    for (int i = 0, j = 0; i < 2 * n; i++) {      
      while (j < 2 * n && s + a[j] <= b) {
        s += a[j++];
      }
      if (j < 2 * n && j - i < right - left) {
        left = i;
        right = j;
      }
      go[i] = j;
      s -= a[i];
    }
    int ans = n;
    for (int start = left; start <= right; start++) {
      int cur = start >= n ? start - n : start;
      int cn = 0;
      for (int i = cur; i < cur + n; i = go[i]) {
        ++cn;
      }
      if (ans > cn) ans = cn;
    }
    printf("%d\n", ans);
  }
}
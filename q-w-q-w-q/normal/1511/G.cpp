#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
int n, m, q, a[200005], ans, l, r, x;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    scanf("%d", a + i);
  a[n + 1] = 1 << 30;
  sort(a + 1, a + n + 1);
  cin >> q;
  while (q--) {
    scanf("%d%d", &l, &r);
    r = upper_bound(a + 1, a + n + 1, r) - a, ans = 0;
    for (int i = upper_bound(a + 1, a + n + 1, l) - a; i < r; i++)
      ans ^= a[i] - l;
    putchar("AB"[ans == 0]);
  }
}
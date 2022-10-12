#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[102][66];

long long num[102];

int solve() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);

    num[i] = 0;
    for (int j = 0; j < m; ++j) {
      num[i] += ((long long) s[i][j] - '0') << (m - j - 1);
    }
  }

  sort(num, num + n);

  long long median = (1LL << (m-1)) - 1;
  for (long long i = median - n*2; i <= median + n*2; ++i) {
    if (i < 0 || binary_search(num, num + n, i)) continue;
    long long l = i+1;
    long long r = (1LL << m) - l;

    for (int j = 0; j < n; ++j) {
      if (num[j] <= i) --l;
      else --r;
    }

    if (l == r || l == r+1) {
      for (int j = m-1; j >= 0; --j) printf("%lld", i >> j & 1);
      printf("\n");
      return 0;
    }
  }
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
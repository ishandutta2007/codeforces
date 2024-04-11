#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int l, r;
long long m;

int solve() {
  scanf("%d %d %lld", &l, &r, &m);

  long long L = m, R = m;
  L += l, R += r;
  L -= r, R -= l;

  L = max(L, 1LL);
  for (int i = l; i <= r; ++i) {
    if (R / i - (L-1) / i <= 0) continue;

    long long num = R - R % i;
    for (int j = l; j <= r; ++j) {
      if (l <= m + j - num && m + j - num <= r) {
        // cerr << num / i << endl;
        printf("%d %lld %d\n", i, m + j - num, j);
        return 0;
      }
    }
  }

  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
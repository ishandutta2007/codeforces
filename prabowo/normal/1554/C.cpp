#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);

  int lg;
  for (lg = 0; ; ++lg) {
    int lo = n & ~((1 << lg + 1) - 1);
    int hi = n | ((1 << lg + 1) - 1);
    // cerr << lo << " " << hi << endl;
    if (m < hi) break;
  }

  int x = n;

  for (; lg >= 0; --lg) {
    int base = x & ~((1 << lg + 1) - 1);
    int delta = ((1 << lg) - 1);
    int bit = n >> lg & 1;
    // bit 0
    {
      int lo = base ^ (bit << lg);
      int hi = lo + delta;

      // cerr << "0: " << lo << " " << hi << endl;

      if (m < hi) {
        x = lo;
        continue;
      }
    }

    // bit 1
    {
      int lo = base ^ ((bit ^ 1) << lg);
      int hi = lo + delta;
      // cerr << "1: " << lo << " " << hi << endl;

      if (m < hi) {
        x = lo;
        continue;
      }
    }
  }

  printf("%d\n", n ^ x);
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
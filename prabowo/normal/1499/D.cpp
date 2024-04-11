#include <bits/stdc++.h>
using namespace std;
 
const int MAXA = 20000005;

int cnt[MAXA];
void sieve() {
  cnt[1] = 0;
  for (int i = 2; i < MAXA; ++i) {
    if (cnt[i] > 0) continue;
    for (int j = i; j < MAXA; j += i) {
      ++cnt[j];
    }
  }
}

int solve() {
  int c, d, x;
  scanf("%d %d %d", &c, &d, &x);

  long long ans = 0;
  for (int g = 1; g*g <= x; ++g) {
    if (x % g != 0) continue;

    long long num = 1LL * d * g + x;
    long long den = 1LL * g * c;
    if (num % den == 0) {
      ans += 1 << cnt[num / den];
      // cerr << g << " " << x << endl;
    }

    if (x / g != g) {
      long long num = 1LL * d * (x / g) + x;
      long long den = 1LL * (x / g) * c;
      if (num % den == 0) {
        ans += 1 << cnt[num / den];
        // cerr << x/g << " " << x << endl;
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}

int main() {
  sieve();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
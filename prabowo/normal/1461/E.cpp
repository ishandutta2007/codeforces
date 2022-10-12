#include <bits/stdc++.h>
using namespace std;
 
long long k, l, r, t, x, y;

// ceil
long long c(long long x, long long y) {
  return (x + y - 1) / y;
}

int solve() {
  scanf("%lld %lld %lld %lld %lld %lld", &k, &l, &r, &t, &x, &y);

  set<long long> vis;
  vis.insert(k);

  long long day = 0;
  while (day < t) {
    long long add = 0;
    if (k + y > r) {
      // Decrease x until can add y again
      add = min(c(k + y - r, x), (k - l) / x);
      k -= add * x;
    } else if (x < y) {
      // Repeatedly add y decrease x
      add = c(r - y + 1 - k, y - x);
      k += add * (y - x);
    } else if (x > y) {
      // Repeatedly add y decrease x
      add = (k - l) / (x - y);
      k += add * (y - x);
    } else {
      return 0 * printf("Yes\n");
    }

    if (add == 0) return 0 * printf("No\n");

    day += add;
    if (day >= t) return 0 * printf("Yes\n");

    if (vis.find(k) != vis.end()) {
      return 0 * printf("Yes\n");
    }

    vis.insert(k);
  }

  printf("Yes\n");
  return 0;
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
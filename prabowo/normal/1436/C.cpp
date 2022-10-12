#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int n, x, p;

int solve() {
  scanf("%d %d %d", &n, &x, &p);

  int l = 0, r = n;
  int smaller = 0, larger = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (p >= mid) {
      l = mid + 1;
      ++smaller;
    } else {
      r = mid;
      ++larger;
    }
  }
  // cerr << smaller << " " << larger << endl;
  if (smaller > x || larger > n - x) return 0 * printf("0\n");
  assert(smaller > 0);
  --smaller;


  int ans = 1;
  for (int i = 0; i < smaller; ++i) {
    ans = 1LL * ans * (x - i - 1) % MOD;
  }
  for (int i = 0; i < larger; ++i) {
    ans = 1LL * ans * (n - x - i) % MOD;
  }
  for (int i = 0; i < n - (smaller + larger + 1); ++i) {
    ans = 1LL * ans * (n - smaller - larger - i - 1) % MOD;
  }

  printf("%d\n", ans);

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
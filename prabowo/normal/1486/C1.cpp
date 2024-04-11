#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int ask(int l, int r) {
  if (l == r) return -1;
  printf("? %d %d\n", l + 1, r + 1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  return ret - 1;
}

int solve() {
  scanf("%d", &n);

  int second = ask(0, n - 1);

  int ans = -1;
  if (ask(0, second) == second) {
    int l = 0, r = second - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ask(mid, n - 1) == second) {
        l = mid + 1;
        ans = mid;
      } else {
        r = mid - 1;
      }
    }
  } else {
    int l = second + 1, r = n - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (ask(0, mid) == second) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }
  }

  printf("! %d\n", ans + 1);
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
#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < 4; ++i) scanf("%d", &a[i]);

  for (int mask = 0; mask < 1 << 4; ++mask) {
    bool can = true;
    for (int i = 0; i < 4; ++i) {
      int ni = (i + 1) % 4;
      int cnt = a[i] - (mask >> i & 1) - (mask >> ni & 1);
      if (cnt >= 0 && cnt <= n - 2);
      else can = false;
    }

    if (can) return 0 * printf("YES\n");
  }

  printf("NO\n");
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
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n;
int a[N];
int pos[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pos[a[i]] = i;
  }

  int ans = 1;
  int l = pos[0], r = pos[0];
  int empty = 0;
  for (int i = 1; i < n; ++i) {
    if (pos[i] < l) {
      empty += l - pos[i] - 1;
      l = pos[i];
    } else if (pos[i] > r) {
      empty += pos[i] - r - 1;
      r = pos[i];
    } else {
      ans = 1LL * ans * empty % MOD;
      --empty;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}
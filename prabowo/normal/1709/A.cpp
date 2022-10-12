#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int a[N];

int solve() {
  int x;
  scanf("%d", &x);
  scanf("%d %d %d", &a[1], &a[2], &a[3]);

  bool can = true;
  if (a[x] == 0 || a[a[x]] == 0) can = false;

  if (can) printf("YES\n");
  else printf("NO\n");
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
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[N];

int solve() {
  for (int i = 0; i < 3; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + 3);

  if (a[1] != a[2]) return 0 * printf("NO\n");

  printf("YES\n%d %d %d\n", a[0], a[0], a[1]);
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
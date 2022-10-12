#include <bits/stdc++.h>
using namespace std;

const int N = 105;

char a[N], b[N], c[N];

int solve() {
  scanf("%s", a);
  scanf("%s", b);
  scanf("%s", c);

  int n = strlen(a);

  for (int i = 0; i < n; ++i) {
    if (c[i] == a[i] || c[i] == b[i]) continue;
    return 0 * printf("NO\n");
  }

  printf("YES\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
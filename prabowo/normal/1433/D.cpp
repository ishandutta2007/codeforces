#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n;
int a[N];

int solve() {
  int n;
  scanf("%d", &n);

  bool same = true;
  int notSame = -1;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] != a[0]) notSame = i;
  }

  if (notSame == -1) return 0 * printf("NO\n");

  printf("YES\n");
  for (int i = 1; i < n; ++i) {
    if (a[i] != a[0]) printf("%d %d\n", 1, i + 1);
  }
  for (int i = 1; i < n; ++i) {
    if (a[i] == a[0]) printf("%d %d\n", notSame + 1, i + 1);
  }

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
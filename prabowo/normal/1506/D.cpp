#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a, a + n);

  int mode = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[j] == a[i]) ++j;

    mode = max(mode, j - i);
    i = j;
  }

  int ans;
  if (mode > n / 2) {
    ans = n - (n - mode) * 2;
  } else {
    ans = (n & 1);
  }

  printf("%d\n", ans);
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
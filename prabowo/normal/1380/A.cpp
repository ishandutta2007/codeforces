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

  for (int j = 0; j < n; ++j) {
    int lft = -1;
    for (int i = 0; i < j; ++i) {
      if (a[i] < a[j]) {
        lft = i;
        break;
      }
    }

    int rgt = -1;
    for (int k = j+1; k < n; ++k) {
      if (a[k] < a[j]) {
        rgt = k;
        break;
      }
    }

    if (lft != -1 && rgt != -1) {
      return 0 * printf("YES\n%d %d %d\n", lft+1, j+1, rgt+1);
    }
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
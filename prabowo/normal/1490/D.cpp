#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];

int d[N];

void dfs(int l, int r, int depth) {
  if (l > r) return;
  int idx = -1;
  for (int i = l; i <= r; ++i) {
    if (idx == -1 || a[i] > a[idx]) {
      idx = i;
    }
  }

  d[idx] = depth;
  dfs(l, idx - 1, depth + 1);
  dfs(idx + 1, r, depth + 1);
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  dfs(0, n - 1, 0);

  for (int i = 0; i < n; ++i) {
    printf("%d ", d[i]);
  }
  printf("\n");
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
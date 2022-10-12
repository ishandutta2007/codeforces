#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, x;
int deg[N];

int solve() {
  scanf("%d %d", &n, &x);
  --x;
  for (int i = 0; i < n; ++i) deg[i] = 0;

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    ++deg[u], ++deg[v];
  }

  if (deg[x] <= 1) return 0 * printf("Ayush\n");
  if (n & 1) printf("Ashish\n");
  else printf("Ayush\n");
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
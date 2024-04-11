#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N], b[N];

int pos[2][N];
int cnt[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    pos[0][a[i] - 1] = i;
    cnt[i] = 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
    pos[1][b[i] - 1] = i;
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = max(ans, ++cnt[(pos[0][i] - pos[1][i] + n) % n]);
  }

  printf("%d\n", ans);
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}
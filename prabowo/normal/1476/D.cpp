#include <bits/stdc++.h>
using namespace std;
 
const int N = 300005;

int n, m, k;
int a[N];
char s[N];

int dpl[N][2];
int lft(int x, int t) {
  if (x == 0) return 0;
  if (~dpl[x][t]) return dpl[x][t];
  if (t == 0 && s[x - 1] == 'L') return dpl[x][t] = lft(x - 1, 1);
  if (t == 1 && s[x - 1] == 'R') return dpl[x][t] = lft(x - 1, 0);
  return dpl[x][t] = x;
}

int dpr[N][2];
int rgt(int x, int t) {
  if (x == n) return n;
  if (~dpr[x][t]) return dpr[x][t];
  if (t == 0 && s[x] == 'R') return dpr[x][t] = rgt(x + 1, 1);
  if (t == 1 && s[x] == 'L') return dpr[x][t] = rgt(x + 1, 0);
  return dpr[x][t] = x;
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  for (int i = 0; i <= n; ++i) dpl[i][0] = dpl[i][1] = dpr[i][0] = dpr[i][1] = -1;

  for (int i = 0; i <= n; ++i) {
    printf("%d ", rgt(i, 0) - lft(i, 0) + 1);
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
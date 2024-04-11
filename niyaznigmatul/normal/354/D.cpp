#include <cstdio>
#include <algorithm>

const int CO = 1111;
const int N = 123456;
const int INF = 1 << 25;

int x[N], y[N], dp[N], id[N], dp2[N];

bool byd(int i, int j) {
  return y[i] == y[j] ? (x[i] > x[j]) : (y[i] < y[j]);
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int cn = 0;
  for (int i = 0; i < k; i++) {
    int cx, cy;
    scanf("%d%d", &cx, &cy);
    --cx;
    --cy;
/*   if (cx < n - CO) {
      ans += 3;
      continue;
    }*/
    x[cn] = cx;
    y[cn] = cy;
    id[cn] = cn;
    ++cn;
  }
  std::sort(id, id + cn, byd);
  for (int i = 0; i <= CO + 1; i++) {
    dp[i] = INF;
  }
  dp[0] = 0;
  int cur = 0;
  for (int cy = 0; cy < n; cy++) {
    int ne = cur;
    while (ne < cn && y[id[ne]] == cy) ++ne;
    dp2[0] = std::min(dp[0], dp[1]) + (ne - cur) * 3;
    int cc2 = dp[0];
    for (int cx = n - 1, i = 1; i <= CO; cx--, i++) {
      if (cx < cy || cx < n - CO) {
        dp2[i] = INF;
        continue;
      }
      if (cur < ne && x[id[cur]] == cx) ++cur;
      int c1 = dp[i + 1];
      if (cc2 > dp[i]) cc2 = dp[i];
      int c2 = cc2;
      int cost = n - cx;
      c2 += ((cost * (cost + 1)) >> 1) + 2;
      if (c1 > c2) c1 = c2;
      dp2[i] = c1 + (ne - cur) * 3;
//      printf("%d %d %d\n", cx, cy, dp2[i]);
    }
    for (int i = 0; i <= CO; i++) dp[i] = dp2[i];
    dp[CO + 1] = INF;
    cur = ne;
  }   
  printf("%d\n", std::min(dp[0], dp[1]));
}
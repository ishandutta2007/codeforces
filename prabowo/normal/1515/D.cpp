#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
 
int n, l, r;
int c[N];
 
int cntL[N], cntR[N];
 
int solve() {
  scanf("%d %d %d", &n, &l, &r);
  for (int i = 0; i < n; ++i) cntL[i] = cntR[i] = 0;
 
  int sumL = 0;
  for (int i = 0; i < l; ++i) {
    scanf("%d", &c[i]);
    ++cntL[--c[i]];
    ++sumL;
  }
 
  int sumR = 0;
  for (int i = l; i < n; ++i) {
    scanf("%d", &c[i]);
    --c[i];
 
    if (cntL[c[i]]) {
      --cntL[c[i]];
      --sumL;
    } else {
      ++cntR[c[i]];
      ++sumR;
    }
  }
 
  int ans = 0;
  if (sumL > sumR) {
    for (int i = 0; i < n; ++i) {
      while (cntL[i] >= 2 && sumL > sumR) {
        sumL -= 2;
        cntL[i] -= 2;
        ++ans;
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      while (cntR[i] >= 2 && sumL < sumR) {
        sumR -= 2;
        cntR[i] -= 2;
        ++ans;
      }
    }
  }
 
  printf("%d\n", ans + max(sumL, sumR));
  return 0;
}
 
int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}
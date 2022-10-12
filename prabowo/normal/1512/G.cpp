#include <bits/stdc++.h>
using namespace std;
 
const int N = 10000005;
 
long long d[N];
int ans[N];
 
int solve() {
  int n;
  scanf("%d", &n);
 
  printf("%d\n", ans[n] == 0 ? -1 : ans[n]);
  return 0;
}
 
void init() {
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) d[j] += i;
  }
 
  for (int i = 1; i < N; ++i) {
    if (d[i] < N && ans[d[i]] == 0) ans[d[i]] = i;
  }
}
 
int main() {
  init();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
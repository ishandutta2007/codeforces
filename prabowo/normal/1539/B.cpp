#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int pre[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);
  scanf("%s", s + 1);

  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + (s[i] - 'a' + 1);
  }

  while (m--) {
    int l, r;
    scanf("%d %d", &l, &r);
    printf("%d\n", pre[r] - pre[--l]);
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}
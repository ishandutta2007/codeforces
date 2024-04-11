#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);
  int mini = 1000;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    mini = min(mini, a[i]);
  }

  int ans = n;
  for (int i = 0; i < n; ++i) {
    if (a[i] == mini) --ans;
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
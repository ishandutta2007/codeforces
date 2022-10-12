#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &m);
  
  int ans = 1000;
  for (int i = 0; i < 10; ++i) {
    if (i == 0 && m == 1) continue;
    int cnt = 0, num = n;
    while (num > 0) {
      ++cnt;
      num /= (m + i);
    }

    ans = min(ans, cnt + i);
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
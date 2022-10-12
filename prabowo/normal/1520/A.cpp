#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  n = unique(s, s + n) - s;

  vector<bool> vis(26, false);

  for (int i = 0; i < n; ++i) {
    if (vis[s[i] - 'A']) return 0 * printf("NO\n");
    vis[s[i] - 'A'] = true;
  }

  printf("YES\n");
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
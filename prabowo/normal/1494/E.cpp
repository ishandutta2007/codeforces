#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m;
char s[5];

map<int, char> edge[N];
map<int, int> turn[N];

int solve() {
  scanf("%d %d", &n, &m);

  long long one = 0, two = 0;
  for (int i = 0; i < m; ++i) {
    scanf("%s", s);

    if (s[0] == '+') {
      int u, v;
      char c;
      scanf("%d %d %c", &u, &v, &c);
      --u, --v;

      edge[u][v] = c;
      if (edge[v][u] == c) ++one;

      ++turn[u][v];
      two += turn[v][u];

    } else if (s[0] == '-') {
      int u, v;
      scanf("%d %d", &u, &v);
      --u, --v;

      char c = edge[u][v];
      if (edge[v][u] == c) --one;
      edge[u][v] = '?';

      two -= turn[v][u];
      --turn[u][v];
    } else {
      int k;
      scanf("%d", &k);

      if (one > 0 || (two > 0 && k % 2 == 1)) printf("YES\n");
      else printf("NO\n");
    }
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
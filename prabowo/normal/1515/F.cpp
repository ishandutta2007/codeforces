#include <bits/stdc++.h>
using namespace std;

const int N = 300005;

int n, m, x;
long long a[N];

vector<pair<int, int>> edges[N];

int ans[N];
bool vis[N];

int front, tail;
void dfs(int u) {
  vis[u] = true;
  for (pair<int, int> p : edges[u]) {
    int v = p.first, i = p.second;
    if (vis[v]) continue;
    dfs(v);
    if (a[u] + a[v] >= x) {
      ans[front++] = i;
      a[u] = a[u] + a[v] - x;
    } else {
      ans[--tail] = i;
    }
  }
}

int solve() {
  scanf("%d %d %d", &n, &m, &x);
  for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    edges[u].emplace_back(v, i);
    edges[v].emplace_back(u, i);
  }

  long long sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  if (sum < 1LL * x * (n - 1)) return 0 * printf("NO\n");

  front = 0; tail = n - 1;
  dfs(0);

  printf("YES\n");
  for (int i = 0; i < n - 1; ++i) {
    printf("%d\n", ans[i] + 1);
  }

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc + 1);
    solve();
  }
  return 0;
}
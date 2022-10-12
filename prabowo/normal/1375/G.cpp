#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 998244353;

int n;
vector<int> edges[N];

int depth[N];
void dfs(int u, int p) {
  for (int v: edges[u]) {
    if (v == p) continue;
    depth[v] = depth[u] + 1;
    dfs(v, u);
  }
}

int solve() {
  scanf("%d", &n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0, 0);

  int cnt[2] = {-1, -1};
  for (int i = 0; i < n; ++i) {
    ++cnt[depth[i] & 1];
  }

  printf("%d\n", min(cnt[0], cnt[1]));
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}
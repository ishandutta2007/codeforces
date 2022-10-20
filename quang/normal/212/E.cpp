#include <bits/stdc++.h>

using namespace std;

const int N = 5010;

int n;
vector <int> a[N], b[N];
int cnt[N];
int res[N], cur[N];

void dfs(int u, int p) {
  cnt[u] =  1;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (v == p) {
      continue;
    }
    dfs(v, u);
    cnt[u] += cnt[v];
    b[u].push_back(cnt[v]);
  }
  b[u].push_back(n - cnt[u]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; i++) {
    memset(cur, 0, sizeof cur);
    cur[0] = 1;
    for (int j = 0; j < b[i].size(); j++) {
      for (int k = n - 2; k >= b[i][j]; k--) {
        cur[k] |= cur[k - b[i][j]];
      }
    }
    for (int j = 0; j < n - 1; j++) {
      res[j] |= cur[j];
    }
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans += res[i];
  }
  cout << ans << endl;
  for (int i = 1; i < n - 1; i++) {
    if (res[i]) {
      cout << i << " " << n - i - 1 << endl;
    }
  }
  return 0;
}
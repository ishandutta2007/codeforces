#include <bits/stdc++.h>
using namespace std;
 
const int N = 400005;

int n;
int a[N];
vector<int> edges[N];
vector<int> pos[N];

int par[N];

pair<int, int> order[N];
int o;
void dfs(int u, int p=-1) {
  order[u].first = o;
  par[u] = p;
  for (int v : edges[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
  order[u].second = o++;
}

struct BIT {
  int sum[N];
  void update(int x, int val) {
    for (int i = x + 1; i <= n; i += i & -i) {
      sum[i - 1] += val;
    }
  }
  int query(int x) {
    int ret = 0;
    for (int i = x + 1; i > 0; i -= i & -i) {
      ret += sum[i - 1];
    }
    return ret;
  }
  int query(int l, int r) {
    return query(r) - query(l - 1);
  }
} bit;

int diff[N];

int solve() {
  scanf("%d", &n);
  vector<int> comp;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    comp.push_back(a[i]);
  }
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end()) - comp.begin());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(comp.begin(), comp.end(), a[i]) - comp.begin();
    pos[a[i]].push_back(i);
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  dfs(0);

  for (int i = 0; i < comp.size(); ++i) {
    if (pos[i].size() <= 1) continue;
    for (int u : pos[i]) bit.update(order[u].second, 1);

    for (int u : pos[i]) {
      int cnt = 0;
      ++diff[order[u].second];
      --diff[order[u].second + 1];

      for (int v : edges[u]) {
        if (v == par[u]) {
          if (bit.query(order[u].first, order[u].second) == pos[i].size()) {
            ++diff[0];
            --diff[order[u].first];
            ++diff[order[u].second + 1];
            --diff[n];
          } else {
            ++cnt;
          }
        } else {
          if (bit.query(order[v].first, order[v].second) == 0) {
            ++diff[order[v].first];
            --diff[order[v].second + 1];
          } else {
            ++cnt;
          }
        }
      }
      if (cnt >= 2) return 0 * printf("0\n");
    }

    for (int u : pos[i]) bit.update(order[u].second, -1);
  }

  int ans = 0, cur = 0;;
  for (int i = 0; i < n; ++i) {
    cur += diff[i];
    if (cur == 0) ++ans;
  }

  printf("%d\n", ans);
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
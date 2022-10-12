#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;
const long long INFLL = 1e18;

int n;
int a[N];

vector<int> edges[N];
vector<pair<int, long long>> pre1[N];
vector<pair<int, long long>> pre2[N];

vector<int> nodes[N];
int mini[N], maxi[N];

int depth[N];
int maxdepth;
void dfs(int u) {
  maxdepth = max(maxdepth, depth[u]);
  nodes[depth[u]].push_back(u);
  for (int v : edges[u]) {
    depth[v] = depth[u] + 1;
    dfs(v);
  }
}

long long dp[N];
long long f(int u) {
  // cerr << u << " " << depth[u] << " " << dp[u] << endl;
  if (depth[u] == maxdepth) return 0;
  if (~dp[u]) return dp[u];

  long long ret = 0;
  for (int v : edges[u]) {
    int d = depth[v];
    ret = max(ret, f(v) + max(a[v] - mini[d], maxi[d] - a[v]));

    int idx = lower_bound(pre1[d].begin(), pre1[d].end(), make_pair(a[v], -INFLL)) - pre1[d].begin();
    if (idx > 0) ret = max(ret, pre2[d][idx - 1].second + a[v]);
    if (idx < pre1[d].size()) ret = max(ret, pre1[d][idx].second - a[v]);

    // if (v == 8) cerr << idx << " " << pre1[d].size() << " " << pre1[d][idx].second << " " << pre2[d][idx - 1].second << " " << a[v] << endl;
  }

  return dp[u] = ret;
}

int solve() {
  scanf("%d", &n);
  maxdepth = 0;
  for (int i = 0; i < n; ++i) {
    edges[i].clear();
    mini[i] = 2e9; maxi[i] = -1;
    pre1[i].clear(); pre2[i].clear();
    nodes[i].clear();
    dp[i] = -1;
  }

  for (int i = 1; i < n; ++i) {
    int u;
    scanf("%d", &u);
    edges[--u].push_back(i);
  }
  for (int i = 1; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  dfs(0);

  for (int d = maxdepth; d > 0; --d) {
    for (int u : nodes[d]) {
      mini[d] = min(mini[d], a[u]);
      maxi[d] = max(maxi[d], a[u]);
      pre1[d].emplace_back(a[u], f(u) + a[u]);
      pre2[d].emplace_back(a[u], f(u) - a[u]);

      // cerr << u << " " << f(u) << " " << depth[u] << endl;
    }
    // cerr << endl;
    sort(pre1[d].begin(), pre1[d].end());
    sort(pre2[d].begin(), pre2[d].end());

    for (int j = (int) pre1[d].size() - 2; j >= 0; --j) {
      pre1[d][j].second = max(pre1[d][j + 1].second, pre1[d][j].second);
    }
    for (int j = 1; j < pre2[d].size(); ++j) {
      pre2[d][j].second = max(pre2[d][j - 1].second, pre2[d][j].second);
    }
  }

  printf("%lld\n", f(0));
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
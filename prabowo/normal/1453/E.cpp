#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
vector<int> edges[N];

int mid;
bool can;
pair<int, int> dfs(int u, int p) {
  pair<int, int> ret = {0, 0};
  vector<int> vv;
  for (int v: edges[u]) {
    if (v == p) continue;

    pair<int, int> p = dfs(v, u);
    ret.first = max(ret.first, max(p.first, p.second + 1));
    vv.push_back(p.second + 1);
  }
  sort(vv.begin(), vv.end());

  if (u == 0) {
    if (vv.size() >= 2) ret.first = max(ret.first, vv[vv.size() - 2] + 1);
    return ret;
  }

  if (vv.size() > 0) {
    if (vv.size() >= 2) ret.first = max(ret.first, vv.back() + 1);
    ret.second = vv[0];
  }

  // cerr << u + 1 << " " << ret.first << " " << ret.second << endl;
  return ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) edges[i].clear();
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  printf("%d\n", dfs(0, 0).first);
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
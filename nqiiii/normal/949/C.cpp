#include <cstdio>
#include <vector>
#include <stack>
using std::vector;
using std::stack;
using std::min;
const int kN = 100010, kInf = 0x3f3f3f3f;
int n, m, h, u[kN], dfn[kN], low[kN], ans_id;
int dfs_cnt, scc[kN], scc_cnt, sz[kN], ans = kInf;
bool vis[kN];
vector<int> graph[kN];
stack<int> stk;
void dfs(int p) {
  dfn[p] = low[p] = ++dfs_cnt;
  stk.push(p);
  for (int i = 0; i< graph[p].size(); ++i) {
    int e = graph[p][i];
    if (!dfn[e]) {
      dfs(e); low[p] = min(low[p], low[e]);
    } else if(!scc[e]) low[p] = min(low[p], dfn[e]);
  }
  if (dfn[p] == low[p]) {
    ++scc_cnt;
    while (1) {
      int t = stk.top(); stk.pop();
      scc[t] = scc_cnt; ++sz[scc_cnt];
      if (t == p) break;
    }
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; ++i) scanf("%d", &u[i]);
  for (int i = 1; i <= m; ++i) {
    int l, r; scanf("%d%d", &l, &r);
    if ((u[l] + 1) % h == u[r]) graph[l].push_back(r);
    if ((u[r] + 1) % h == u[l]) graph[r].push_back(l);
  }
  for (int i = 1; i <= n; ++i) if (!dfn[i]) dfs(i);
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < graph[i].size(); ++j) {
      int e = graph[i][j];
      if (scc[e] != scc[i]) vis[scc[i]] = 1;
    }
  for (int i = 1; i <= scc_cnt; ++i)
    if (!vis[i] && sz[i] < ans) {
      ans = sz[i]; ans_id = i;
    }
  printf("%d\n", ans);
  for (int i = 1; i <= n; ++i) if (scc[i] == ans_id)
    printf("%d ", i);
}
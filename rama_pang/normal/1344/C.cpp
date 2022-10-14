#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int MAXN = 200005;

int N, M;
vector<int> adj[MAXN];
vector<int> radj[MAXN];

int comp[MAXN];

int vis[MAXN];

void dfs(int n, vector<int> &topo) {
  if (vis[n]) return;
  vis[n] = 1;
  for (auto i : adj[n]) dfs(i, topo);
  topo.emplace_back(n);
}

void dfs2(int n, int c) {
  if (vis[n]) return;
  vis[n] = 1;
  comp[n] = c;
  for (auto i : radj[n]) dfs2(i, c);
}

void SCC() {
  memset(comp, -1, sizeof(comp));
  memset(vis, 0, sizeof(vis));
  vector<int> topo;
  for (int i = 1; i <= N; i++) dfs(i, topo);
  reverse(begin(topo), end(topo));
  memset(vis, 0, sizeof(vis));
  for (auto i : topo) {
    if (!vis[i]) {
      dfs2(i, i);
    }
  }

  for (int i = 1; i <= N; i++) {
    if (comp[i] != i) {
      cout << -1 << "\n";
      exit(0);
    }
  }
}

int mark_adj[MAXN];
int mark_radj[MAXN];

void dfs_adj(int n) {
  mark_adj[n] = 1;
  for (auto i : adj[n]) if (!mark_adj[i]) dfs_adj(i);
}

void dfs_radj(int n) {
  mark_radj[n] = 1;
  for (auto i : radj[n]) if (!mark_radj[i]) dfs_radj(i);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> N >> M;
  vector<pair<int, int>> edges(M);
  for (int i = 0; i < M; i++) {
    cin >> edges[i].first >> edges[i].second;
    adj[edges[i].first].emplace_back(edges[i].second);
    radj[edges[i].second].emplace_back(edges[i].first);
  }

  SCC();

  int cnt = 0;
  string ans(N + 1, 'E');

  for (int i = 1; i <= N; i++) {
    if (!mark_adj[i] && !mark_radj[i]) {
      ans[i] = 'A';
      cnt++;
    }
    dfs_adj(i);
    dfs_radj(i);
  }

  cout << cnt << "\n";
  for (int i = 1; i <= N; i++) {
    cout << ans[i];
  }
  cout << "\n";
  return 0;
}
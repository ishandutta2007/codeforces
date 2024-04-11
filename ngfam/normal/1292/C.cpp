#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3003;

int n, w;
int par[MAXN];
int child[MAXN];
vector<int> g[MAXN];

int nxt[MAXN][MAXN];
bool done[MAXN][MAXN];
long long f[MAXN][MAXN];

void dfs_prepare(int v, int p) {
  par[v] = p;
  child[v] = 1;
  for(int s : g[v]) if(s != p) {
    dfs_prepare(s, v);
    child[v] += child[s];
  }
}

int calc(int u, int v) {
  if(u == par[v]) {
    return n - child[v];
  }
  else {
    return child[u];
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    --u; --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  dfs_prepare(0, -1);

  queue<pair<int, int>> paths;
  for(int u = 0; u < n; ++u) {
    for(int v : g[u]) {
      nxt[u][v] = v;
      int w = calc(u, v);
      f[u][v] = w * (n - w);
      paths.emplace(u, v);
    }
  }

  long long ans = 0;

  while(!paths.empty()) {
    auto p = paths.front(); paths.pop();
    int u = p.first, v = p.second;
    if(done[u][v]) continue;
    done[u][v] = 1;

    ans = max(ans, f[u][v]);

    for(int x : g[u]) {
      if(x != nxt[u][v]) {
        nxt[x][v] = u;
        int w1 = calc(x, u);
        int y = nxt[v][u];
        int w2 = calc(v, y);
        f[x][v] = max(f[x][v], f[u][v] + w1 * w2);
        f[v][x] = max(f[v][x], f[x][v]);
        paths.emplace(x, v);
      }
    }
  }

  cout << ans << "\n";

  return 0;
}
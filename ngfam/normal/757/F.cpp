#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
const int LG = 20;

int n, m, s;
int done[maxn];
long long f[maxn];
vector<pair<int, int>> g[maxn];

int height[maxn];
int jump[maxn][LG];

int LCA(int u, int v) {
  if(u == -1) return v;
  if(v == -1) return u;
  if(height[u] < height[v]) swap(u, v);
  for(int i = LG - 1; i >= 0; --i) {
    if(jump[u][i] != -1 && height[jump[u][i]] >= height[v]) {
      u = jump[u][i];
    }
  }
  if(u == v) return v;
  for(int i = LG - 1; i >= 0; --i) {
    if(jump[u][i] != jump[v][i]) {
      u = jump[u][i];
      v = jump[v][i];
    }
  }
  return jump[v][0];
}

int cnt[maxn];
int adj[maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  memset(f, 60, sizeof f);

  cin >> n >> m >> s; --s;
  for(int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[--u].emplace_back(--v, w);
    g[v].emplace_back(u, w);
  }

  set<pair<long long, int>> que;
  que.emplace(f[s] = 0, s);

  while(!que.empty()) {
    int v = que.begin() -> second; que.erase(que.begin());
    if(done[v]) continue;
    done[v] = 1;
    for(auto &e : g[v]) {
      int u = e.first, w = e.second;
      if(f[u] > f[v] + w) que.emplace(f[u] = f[v] + w, u);
    }
  }

  memset(jump, -1, sizeof jump);

  vector<int> perm;
  for(int i = 0; i < n; ++i) perm.push_back(i);

  sort(perm.begin(), perm.end(), [&](int u, int v){
    return f[u] < f[v];
  });

  for(int i = 1; i < n; ++i) {
    int v = perm[i];
    if(f[v] == f[maxn - 1]) continue;
    int par = -1;
    for(auto &e : g[v]) {
      int u = e.first, w = e.second;
      if(f[v] == f[u] + w) {
        par = LCA(par, u);
      }
    }
    adj[v] = par;
    jump[v][0] = par;
    height[v] = height[par] + 1;
    for(int j = 1; j < LG; ++j) if(jump[v][j - 1] != -1) jump[v][j] = jump[jump[v][j - 1]][j - 1];
  }

  int ans = 0;

  for(int i = n - 1; i > 0; --i) {
    int v = perm[i];
    if(f[v] == f[maxn - 1]) continue;
    ans = max(ans, cnt[v] + 1);
    cnt[adj[v]] += cnt[v] + 1;
  }

  cout << ans << endl;

  return 0;
}
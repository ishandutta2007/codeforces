#include<bits/stdc++.h>

using namespace std;

const int MAXN = 200020;

int n;
vector<int> adj[MAXN];
pair<int, int> f[MAXN], g[MAXN];

void dfs_up(int v, int p) {
  f[v] = make_pair(-1, v);
  for(int s : adj[v]) if(s != p) {
    dfs_up(s, v);
    f[v] = max(f[v], f[s]);
  }
  ++f[v].first;
}

vector<int> ans = {0, 0, 0, 0, 0};

void dfs_down(int v, int p) {
  set<pair<int, int>> best = {g[v]};
  for(int s : adj[v]) if(s != p){
    best.emplace(make_pair(f[s].first + 1, f[s].second));
  }
  for(int s : adj[v]) if(s != p) {
    auto it = best.end(); --it;
    if(it -> second == f[s].second) --it;
    g[s] = make_pair(it -> first + 1, it -> second);
    dfs_down(s, v);
  }

  vector<int> cur = {0, 0, v, v, v};
  for(int i = 0; i < 3; ++i) {
    if(best.empty()) break;
    cur[1] = i + 1;
    auto p = *best.rbegin();
    best.erase(p);
    cur[0] += p.first;
    cur[i + 2] = p.second;
    ans = max(ans, cur);
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n;
  for(int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    adj[--u].push_back(--v);
    adj[v].push_back(u);
  }

  dfs_up(0, -1);
  dfs_down(0, -1);

  cout << ans[0] << endl;
  for(int i = 0; i < 3; ++i) {
    cout << ans[i + 2] + 1 << " ";
  }

  return 0;
}
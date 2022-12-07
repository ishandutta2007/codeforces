#include<bits/stdc++.h>

using namespace std;

const int N = 1000050;

int n, m;
int visited[N];
vector < int > g[N];
map < pair < int, int >, int > w, mark;


pair < int, int > edges[N];

int go(int x, int pre, vector < int > &vec, int need) {
  int p = find(vec.begin(), vec.end(), x) - vec.begin();
  while(true) {
    int nxt = vec[(p + 1) % vec.size()];
    if(nxt == pre) nxt = vec[(p - 1 + vec.size()) % vec.size()];
    if(w[{vec[p], nxt}] == need) return 1;
    if(w[{vec[p], nxt}] < w[{pre, vec[p]}]) return 0;
    pre = vec[p];
    if(nxt == vec[(p + 1) % vec.size()]) p = (p + 1) % vec.size();
    else p = (p - 1 + vec.size()) % vec.size();
  }
  return 0;
}

int is_special[N];

void dfs(int v, int p) {
  visited[v] = p;
  for(int s : g[v]) if (s != p) {
    if(!visited[s]) dfs(s, v);
    else {
      if(visited[s] == -2) continue;
      int min_edge = w[{v, s}], max_edge = min_edge;
      vector < int > lst = {v};
      for(int x = v; x != s; x = visited[x]) {
        lst.push_back(visited[x]);
        min_edge = min(min_edge, w[{x, visited[x]}]);
        max_edge = max(max_edge, w[{x, visited[x]}]);
      }
      if(go(edges[min_edge].first, edges[min_edge].second, lst, max_edge) &&
         go(edges[min_edge].second, edges[min_edge].first, lst, max_edge)) {
           is_special[min_edge] = max_edge;
      }
    }
  }
  visited[v] = -2;
}

long long f[N], ans[N];

int get(int x, int bound) {
  vector < pair < int, int > > cand;
  for(int v : g[x]) if(w[{v, x}] > bound) cand.emplace_back(w[{v, x}], v);
  sort(cand.rbegin(), cand.rend());
  if(cand.size()) return f[cand.back().second] - 1;
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  if(fopen("inp", "r")) freopen("inp", "r", stdin);

  cin >> n >> m;
  for(int i = 1; i <= m; ++i) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    w[{u, v}] = w[{v, u}] = i;
    edges[i] = make_pair(u, v);
  }

  dfs(1, -1);
  for(int i = 1; i <= n; ++i) f[i] = 1;
  for(int i = m; i >= 1; --i) {
    int u = edges[i].first, v = edges[i].second;
    if(!is_special[i]) {
      f[u] += f[v];
      ans[i] = f[v] = f[u];
    }
    else {
      f[u] = f[v] = (f[u] + f[v] - ans[is_special[i]]);
    }
  }

    for(int i = 1; i <= n; ++i) cout << f[i] - 1 << " ";
    cout << endl;

  return 0;
}
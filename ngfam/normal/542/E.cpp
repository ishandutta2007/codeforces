#include<bits/stdc++.h>

/***
 arent all cycles the same wut
 another approach:
 Keep finding shortest cycle and transform the graph

 basically maximum shortest path between any pair of vertices
 i thought of this from the start but got distracted by shitty
 solution
***/

using namespace std;

const int MAXN = 2010;

struct dsu{
  int par[MAXN];
  dsu() {
    for(int i = 0; i < MAXN; ++i) par[i] = i;
  }
  int find(int v) {
    return par[v] == v ? v : par[v] = find(par[v]);
  }
  void join(int u, int v) {
    u = find(u); v = find(v);
    if(u == v) return;
    par[u] = v;
  }
}dsu;

int n, m, f[MAXN];
vector<int> g[MAXN];

int visited[MAXN];

void dfs_check(int v){
  for(int s : g[v]) {
    if(visited[s]) {
      if(visited[v] % 2 == visited[s] % 2) {
        cout << -1;
        exit(0);
      }
    }
    else {
      visited[s] = visited[v] + 1;
      dfs_check(s);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m;
  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
    dsu.join(u, v);
  }

  vector<int> ans(n, 0);

  for(int i = 0; i < n; ++i) {
    if(!visited[i]) {
      visited[i] = 1;
      dfs_check(i);
    }
  }

  for(int i = 0; i < n; ++i) {
    fill(f, f + n, n + 1);
    f[i] = 0;
    deque<int> que = {i};
    while(!que.empty()) {
      int v = que.front(); que.pop_front();
      for(int s : g[v]) if(f[s] > f[v] + 1) {
        f[s] = f[v] + 1;
        que.push_back(s);
      }
    }

    for(int j = 0; j < n; ++j) {
      if(dsu.find(i) == dsu.find(j)) {
        ans[dsu.find(i)] = max(ans[dsu.find(i)], f[j]);
      }
    }
  }

  cout << accumulate(ans.begin(), ans.end(), 0) << endl;

  return 0;
}
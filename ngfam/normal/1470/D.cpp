#include <bits/stdc++.h>

using namespace std;

const int maxn = 300005;

int n, m;
vector<int> g[maxn];

int visited[maxn];
int count_vertices;

void dfs_connectivity(int v) {
  visited[v] = 1;
  count_vertices++;
  for(int s : g[v]) if(!visited[s]) dfs_connectivity(s);
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);  

  int ntest; cin >> ntest;

  while(ntest--) {
    cin >> n >> m;
    while(m--) {
      int u, v; cin >> u >> v;
      g[--u].push_back(--v);
      g[v].push_back(u);
    }

    dfs_connectivity(0);
    if (count_vertices != n) {
      cout << "NO\n";
      count_vertices = 0;
      for(int i = 0; i < n; ++i) {
        g[i].clear();
        visited[i] = 0;
      }
      continue;
    }

    vector<int> answer;
    set<int> unconnected;
    set<int> pickable;
    set<int> unpickable;
    vector<bool> already_removed(n, false);

    for(int i = 0; i < n; ++i) unconnected.insert(i);

    auto remove_unconnected = [&](int v) {
      if(already_removed[v]) return;
      unconnected.erase(v);
      pickable.erase(v);
      already_removed[v] = 1;
      for(int s : g[v]) if(unconnected.count(s) && !unpickable.count(s)) {
        pickable.insert(s);
      } 
    };

    auto add_vertex = [&](int v) {
      pickable.erase(v);
      answer.push_back(v + 1);
      unconnected.erase(v); 
      for(int s : g[v]) remove_unconnected(s), unpickable.insert(s);
      return;
    };

    add_vertex(0);
    while(!unconnected.empty()) {
      if (!pickable.size()) {
        cout << *unconnected.begin() << endl;
        exit(0);
      }
      add_vertex(*pickable.begin());
    }

    cout << "YES\n";
    cout << answer.size() << "\n";
    for(int x : answer) cout << x << " ";
    cout << "\n";

    count_vertices = 0;
    for(int i = 0; i < n; ++i) {
      g[i].clear();
      visited[i] = 0;
    }
    
  }

  return 0;
}
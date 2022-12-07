#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n; cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i + 1 < n; ++i) {
      int u, v; cin >> u >> v;
      --u; --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }

    vector<int> first(n), second(n);

    int x, y, v;
    cin >> x;
    for(int i = 0; i < x; ++i) {
      int u; cin >> u;
      first[--u] = 1;
    }

    cin >> y;
    for(int i = 0; i < y; ++i) {
      cin >> v; --v;
      second[v] = 1;
    }

    cout << "B " << v + 1 << endl;
    int node; cin >> node;

    node--;
    queue<int> bfs;
    bfs.push(node);

    vector<int> visited(n);
    visited[node] = 1;

    int node2;
    while(!bfs.empty()){
      int x = bfs.front(); bfs.pop();
      if(first[x]) {
        node2 = x;
        break;
      }
      for(int y : g[x]) {
        if(!visited[y]) {
          visited[y] = 1;
          bfs.push(y);
        }
      }
    }

    cout << "A " << node2 + 1 << endl;
    int gg_tanphat_orz; cin >> gg_tanphat_orz;

    --gg_tanphat_orz;

    if(second[gg_tanphat_orz]) {
      cout << "C " << node2 + 1 << endl;
    }
    else {
      cout << "C " << -1 << endl;
    }
  }

  return 0;
}
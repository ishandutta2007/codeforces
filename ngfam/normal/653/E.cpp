#include<bits/stdc++.h>

/***
  first do bfs on the graph without vertice 1
  wrong conditions:
    1. number of connected component > k
    2. theres some connected component unable to be connected to 1
    3. degree of 1 < k
***/

using namespace std;

const int MAXN = 300003;

int n, m, k;
set<int> g[MAXN];
vector<int> rem[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  cin >> n >> m >> k;
  for(int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v;
    g[--u].insert(--v);
    g[v].insert(u);
  }

  set<int> avail;
  for(int i = 1; i < n; ++i) {
    avail.insert(i);
  }

  while(!avail.empty()) {
    vector<int> que;
    que.emplace_back(*avail.begin());
    avail.erase(avail.begin());
    int count = 0;
    while(!que.empty()) {
      int x = que.back(); que.pop_back();
      if(!g[0].count(x)) rem[count++].push_back(x);
      for(auto it = avail.begin(); it != avail.end();){
        int y = *it;
        if(g[x].count(y)) {
          it++;
          continue;
        }
        que.push_back(y);
        it = avail.erase(it);
      }
    }
    if(count == 0) {
      cout << "impossible" << endl;
      return 0;
    }
  }

  if(k < rem[0].size()) {
    cout << "impossible" << endl;
    return 0;
  }
  for(int i = 0; i < MAXN; ++i) {
    k -= rem[i].size();
  }

  if(k > 0) cout << "impossible" << endl;
  else cout << "possible" << endl;

  return 0;
}
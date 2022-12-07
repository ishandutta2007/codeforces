#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 100010;
 
int n, m, k, q;
vector < pair < int, int > > g[N];
 
bool done[N];
int in_comp[N];
pair < long long, int > d[N]; /// (shortest path, source)
pair < long long, int > best[N];
 
vector < int > elements[N];
vector < pair < int, long long > > changes[N];
 
void join(int x, int y, long long w) {
  if(elements[x].size() < elements[y].size()) swap(x, y);
  for(int s : elements[y]) {
    in_comp[s] = x;
    elements[x].push_back(s);
    changes[s].emplace_back(x, w);
  }
  elements[y].clear();
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  cin >> n >> m >> k >> q;
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
 
  for(int i = 1; i <= k; ++i) {
    in_comp[i] = i;
    elements[i].push_back(i);
    changes[i].emplace_back(i, 0);
  }
 
  for(int rep = 0; rep < 1; ++rep){
    memset(d, 60, sizeof d);
    memset(done, false, sizeof done);
 
    set < pair < long long, int > > que;
 
    for(int i = 1; i <= k; ++i) {
      d[i] = make_pair(0LL, i);
      que.emplace(0LL, i);
    }
 
    while(!que.empty()) {
      int x = que.begin() -> second; que.erase(que.begin());
      if(done[x]) continue;
      done[x] = true;
      for(auto e : g[x]) {
        int v = e.first, w = e.second;
        if(d[v].first > d[x].first + w) {
          d[v] = make_pair(d[x].first + w, d[x].second);
          que.emplace(d[v].first, v);
        }
      }
    }
 
    memset(best, 60, sizeof best);
 
    vector < pair < long long, pair < int, int > > > edges;
 
    for(int u = 1; u <= n; ++u) {
      for(auto e : g[u]) {
        int v = e.first, w = e.second;
        int a = d[u].second, b = d[v].second;
        if(in_comp[a] == in_comp[b]) continue;
        edges.emplace_back(d[u].first + d[v].first + w, make_pair(a, b));
      }
    }
 
    sort(edges.begin(), edges.end());
    for(auto p : edges) {
      int u = p.second.first, v = p.second.second;
      if(in_comp[u] == in_comp[v]) continue;
      join(in_comp[u], in_comp[v], p.first);
    }
  }
 
 
  while(q--) {
    int u, v; cin >> u >> v;
    long long ans = 1e18;
    for(auto p : changes[u]) {
      for(auto q : changes[v]) {
        if(p.first == q.first) {
          ans = min(ans, max(p.second, q.second));
        }
      }
    }
    cout << ans << "\n";
  }
 
  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <iomanip>
#include <deque>

using namespace std;

vector<int> p;
vector<int> mx;

int get(int u){
  if (p[u] == u)
    return u;
  return (p[u] = get(p[u]));
}

int merge(int u, int v){
  u = get(u);
  v = get(v);
  if (u == v)
    return u;
  p[u] = v;
  mx[v] = max(mx[v], mx[u]);
  return v;
}

void dfs(int v, int num, vector<int> &comps, vector<vector<int>> &G){
  comps[v] = num;
  for (int u : G[v]){
    if (comps[u] == -1)
      dfs(u, num, comps, G);
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  p.resize(n);
  mx.resize(n);
  for (int i = 0; i < n; ++i){
    p[i] = i;
    mx[i] = i;
  }
  vector<vector<int>> G(n);
  for (int i = 0; i < m; ++i){
    int x, y;
    cin >> x >> y;
    G[x - 1].emplace_back(y - 1);
    G[y - 1].emplace_back(x - 1);
  }
  vector<int> comps(n, -1);
  int cnt = 0;
  for (int i = 0; i < n; ++i){
    if (comps[i] == -1){
      dfs(i, cnt, comps, G);
      ++cnt;
    }
  }
  vector<int> prev(cnt, -1);
  for (int i = 0; i < n; ++i){
    if (prev[comps[i]] != -1)
      merge(i, prev[comps[i]]);
    prev[comps[i]] = i;
  }
  int now = get(0);
  int ans = 0;
  for (int i = 0; i < n; ++i){
    if (i > mx[now]){
      now = get(i);
    }
    if (get(i) != now){
      ++ans;
      now = merge(i, now);
    }
  }
  cout << ans;
  return 0;
}
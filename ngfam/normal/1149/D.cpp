#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 77;
 
int n, m, a, b;
int lab[N];
vector < pair < int, int > > g[N];
 
int find(int x) {
  if(lab[x] < 0) return x;
  return lab[x] = find(lab[x]);
}
 
void join(int u, int v) {
  u = find(u); v = find(v);
  lab[v] = u;
}
 
int comp[N];
int reIdx[N];
int cntComp[N];
 
 
const int M = 18;
int f[N][1 << M];
 
bool minimize(int &u, int v) {
  if(u > v) {
    u = v;
    return true;
  }
  return false;
}
 
int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
  cin >> n >> m >> a >> b;
 
  vector < pair < int, int > > edges[2];
 
  memset(lab, -1, sizeof lab);
 
  for(int i = 1; i <= m; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
 
    if(w == a) edges[0].emplace_back(u, v);
    else edges[1].emplace_back(u, v);
 
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }
 
  for(auto &e : edges[0]) if(find(e.first) != find(e.second)) join(e.first, e.second);
 
  for(int i = 1; i <= n; ++i) {
    ++cntComp[find(i)];
  }
 
  int cnt = 0;
 
  for(int i = 1; i <= n; ++i) {
    int x = find(i);
    if(cntComp[x] < 4) continue;
    if(!reIdx[x]) reIdx[x] = ++cnt;
    comp[i] = reIdx[x];
  }
 
  memset(f, 60, sizeof f);
 
  if(comp[1] > 0) f[1][1 << (comp[1] - 1)] = 0;
  else {
    f[1][0] = 0;
  }
 
    for(int mask = 0; mask < (1 << cnt); ++mask) {
 
    set < pair < int, int > > mySet;
 
    for(int i = 1; i <= n; ++i) {
      mySet.emplace(f[i][mask], i);
    }
 
    vector < bool > mark(n + 5, false);
 
    while(!mySet.empty()) {
      int v = mySet.begin() -> second; mySet.erase(mySet.begin());
 
      if(mark[v]) continue;
      mark[v] = true;
 
      for(auto &e : g[v]) {
        int s = e.first, w = e.second;
        if(mark[s]) continue;
        if(w == a) {
          if(minimize(f[s][mask], f[v][mask] + a)) {
            mySet.emplace(f[s][mask], s);
          }
        }
        else {
          if(comp[s] || find(s) == find(v)) continue;
 
          if(minimize(f[s][mask], f[v][mask] + b)){
            mySet.emplace(f[s][mask], s);
          }
        }
      }
    }
 
    for(int v = 1; v <= n; ++v) {
      for(auto &e : g[v]) {
        int s = e.first, w = e.second;
        if(w != b) continue;
 
        if(cntComp[find(s)] < 4) {
          continue;
        }
 
        int newmask = mask | (1 << (comp[s] - 1));
        if(newmask == mask) continue;
        minimize(f[s][newmask], f[v][mask] + b);
      }
    }
  }
 
 
  for(int i = 1; i <= n; ++i) {
    int ret = 1e9;
    for(int mask = 0; mask < (1 << cnt); ++mask) {
      ret = min(ret, f[i][mask]);
    }
    cout << ret << " ";
  }
 
  return 0;
}
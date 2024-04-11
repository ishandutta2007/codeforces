#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vecint> g(n), rg(n);
  REP(i,m) {
    int u,v;
    cin>>u>>v;
    --u;--v;
    g[u].push_back(v);
    rg[v].push_back(u);
  }
  int k;
  cin>>k;
  vecint p(k);
  for(auto&& e:p) {
    cin>>e;
    --e;
  }
  int t = p.back();
  queue<int> q;
  q.push(t);
  constexpr int INF = 1e9;
  vecint dist(n,INF);
  dist[t] = 0;
  while (!q.empty()) {
    int i = q.front();
    q.pop();
    for(auto&& to:rg[i]) {
      if (dist[to] > dist[i] + 1) {
        dist[to] = dist[i] + 1;
        q.push(to);
      }
    }
  }
  int mn = 0, mx = 0;
  REP(i,k-1) {
    if (dist[p[i]] == dist[p[i+1]] + 1) {
      int cnt = 0;
      for(auto&& to:g[p[i]]) {
        if (dist[p[i]] == dist[to] + 1) ++cnt;
      }
      if (cnt >= 2) ++mx;
    } else {
      ++mn;
      ++mx;
    }
  }
  cout<<mn<<' '<<mx<<endl;
  return 0;
}
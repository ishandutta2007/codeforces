#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct Edge {
  int src, dest, weight;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n,m;
  cin>>n>>m;
  vector<string> mat(n);
  REP(i,n)cin>>mat[i];
  auto idx = [&] (int r, int c) {
    return r * m + c;
  };
  vector<vector<Edge>> g(n*m);
  vecint vs(3);
  REP(i,n)REP(j,m) {
    int dij[] = {1, 0, -1, 0, 1};
    if (mat[i][j] == '#') continue;
    if (mat[i][j] != '.') {
      vs[mat[i][j] - '1'] = idx(i,j);
    }
    REP(k,4) {
      int ni = i + dij[k];
      int nj = j + dij[k+1];
      if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
      if (mat[ni][nj] == '.') {
        g[idx(i,j)].push_back({idx(i,j),idx(ni,nj),1});
      } else {
        g[idx(i,j)].push_back({idx(i,j),idx(ni,nj),0});
      }
    }
  }
  constexpr int INF = 1e8;
  vector d(3, vector(n*m, INF));
  REP(i,3) {
    deque<int> q;
    q.push_back(vs[i]);
    d[i][vs[i]] = 0;
    while (!q.empty()) {
      int id = q.front();
      q.pop_front();
      for (auto&& e : g[id]) {
        if (d[i][e.dest] > d[i][e.src] + e.weight) {
          d[i][e.dest] = d[i][e.src] + e.weight;
          if (e.weight) {
            q.push_back(e.dest);
          } else {
            q.push_front(e.dest);
          }
        }
      }
    }
  }
  int mn = INF;
  REP(i,n)REP(j,m) {
    int tmp = 0;
    if (mat[i][j] == '#') continue;
    if (mat[i][j] == '.') tmp -= 2;
    REP(k,3) {
      tmp += d[k][idx(i,j)];
    }
    mn = min(mn, tmp);
  }
  if (mn < INF) {
    cout<<mn<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}
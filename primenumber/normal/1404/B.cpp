#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
constexpr int INF = 1e8;

void dfs(const vector<vecint>& g, int d, vecint& vd, int i, int p = -1) {
  vd[i] = d;
  for (auto&&to:g[i]) {
    if (to == p) continue;
    dfs(g, d+1, vd, to, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin>>t;
  REP(cnum,t) {
    int n,a,b,da,db;
    cin>>n>>a>>b>>da>>db;
    --a;--b;
    vector<vecint> g(n);
    REP(i,n-1) {
      int x,y;
      cin>>x>>y;
      --x;--y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    if (db <= 2*da) {
      cout<<"Alice\n";
      continue;
    }
    vecint dista(n, INF);
    dfs(g, 0, dista, a);
    if (dista[b] <= da) {
      cout<<"Alice\n";
      continue;
    }
    int d1 = max_element(ALL(dista)) - begin(dista);
    vecint distd(n, INF);
    dfs(g, 0, distd, d1);
    int d2 = max_element(ALL(distd)) - begin(distd);
    int diam = distd[d2];
    if (diam <= 2*da) {
      cout<<"Alice\n";
      continue;
    }
    cout<<"Bob\n";
  }
  return 0;
}
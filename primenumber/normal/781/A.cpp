#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

void dfs(const vector<vecint>& g, vecint& clr, int i, int p = -1) {
  int sz = size(g[i]);
  int cnt = 1;
  REP(j,sz) {
    int to = g[i][j];
    if (to == p) continue;
    while (cnt == clr[i] || (p >= 0 && cnt == clr[p])) ++cnt;
    clr[to] = cnt;
    ++cnt;
    dfs(g, clr, to, i);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin>>n;
  vector<vecint> g(n);
  REP(i,n-1) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int mx = 0;
  REP(i,n) mx = max(mx, (int)size(g[i]));
  vecint clr(n, 0);
  REP(i,n) {
    if (size(g[i]) == mx) {
      clr[i] = 1;
      dfs(g, clr, i);
      break;
    }
  }
  cout << mx+1 << "\n";
  REP(i,n) {
    if(i) cout<<" ";
    cout<<clr[i];
  }
  cout<<"\n";
  return 0;
}
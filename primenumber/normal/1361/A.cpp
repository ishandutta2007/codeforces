#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vecint> g(n);
  REP(i,m) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vecint t(n);
  for(auto&&e:t)cin>>e;
  vector<tuple<int,int>> vt;
  REP(i,n) {
    vt.emplace_back(t[i], i);
  }
  sort(ALL(vt));
  bool valid = true;
  vecint ans(n);
  REP(j,n) {
    auto[ti,i] = vt[j];
    if (ti > g[i].size() + 1) {
      valid = false;
      break;
    }
    vector<bool> has(ti+1, false);
    for(auto&&to:g[i]) {
      if (t[to] > ti) continue;
      has[t[to]] = true;
    }
    if (has[ti]) {
      valid = false;
      break;
    }
    FOR(k,1,ti) {
      if (!has[k]) {
        valid = false;
        break;
      }
    }
    if (!valid) break;
    ans[j] = i;
  }
  if (!valid) {
    cout<<-1<<"\n";
    return 0;
  }
  REP(i,n) {
    if (i)cout<<" ";
    cout<<ans[i]+1;
  }
  cout<<endl;
  return 0;
}
#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

constexpr ll hoge = 1234567890123l;

tuple<int,bool> dfs(const vector<vecint>& g, vecint& clr, int i, int c, int p = -1) {
  int high = 0;
  int cntl = 0;
  int cntc = 0;
  for (auto&& to : g[i]) {
    if (to == p) continue;
    ++cntc;
    clr[to] = 1 - c;
    auto [mx, isl] = dfs(g, clr, to, 1-c, i);
    if (isl) ++cntl;
    high += mx;
  }
  if (cntc == 0) {
    // nothing
  } else if (cntl) {
    high += cntc - cntl + 1;
  } else {
    high += cntc;
  }
  //cerr<<i<<" "<<mode<<endl;
  return make_tuple(high, cntc == 0);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
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
  int nl = -1;
  REP(i,n) if (g[i].size() > 1) nl = i;
  vecint clr(n, -1);
  clr[nl] = 0;
  auto [mx, _] = dfs(g, clr, nl, 0);
  int mn = 1;
  int mode = 0;
  REP(i,n) if (g[i].size() == 1) mode |= 1 << clr[i];
  if (mode >= 3) mn = 3;
  cout<<mn<<" "<<mx<<endl;
  return 0;
}
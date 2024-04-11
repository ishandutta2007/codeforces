#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

bool isdag(const vector<vecint>& g, vecint& state, int i) {
  state[i] = 1;
  for (auto&& to : g[i]) {
    if (state[to] == 1) return false;
    if (state[to] == 2) continue;
    if (!isdag(g, state, to)) return false;
  }
  state[i] = 2;
  return true;
}

int dfs(const vector<vecint>& g, vecint& mn, int i) {
  int n = g.size();
  int tmp = n;
  for (auto&& to : g[i]) {
    if (mn[to] == n) {
      dfs(g, mn, to);
    }
    tmp = min(tmp, mn[to]);
  }
  mn[i] = min(tmp, i);
  return tmp;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  vector<vecint> g(n), rg(n);
  REP(i,m) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    g[a].push_back(b);
    rg[b].push_back(a);
  }
  vecint state(n, 0);
  REP(i,n) {
    if (state[i] == 0) {
      if (!isdag(g, state, i)) {
        cout<<-1<<endl;
        return 0;
      }
    }
  }
  vecint mn(n, n);
  vecint mnr(n, n);
  REP(i,n) {
    if (mn[i] == n) dfs(g, mn, i);
    if (mnr[i] == n) dfs(rg, mnr, i);
  }
  int cnt = 0;
  stringstream ss;
  REP(i,n) {
    if (mn[i] == i && mnr[i] == i) {
      ++cnt;
      ss << 'A';
    } else {
      ss << 'E';
    }
  }
  cout<<cnt<<"\n";
  cout<<ss.str()<<endl;
  return 0;
}
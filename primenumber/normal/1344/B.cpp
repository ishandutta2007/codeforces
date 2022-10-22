#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

struct UnionFind {
  vector<int> parent;
  UnionFind (int n) : parent(n, -1) {}
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  UnionFind uf(n+m);
  vector<string> t(n);
  REP(i,n) cin>>t[i];
  REP(i,n)REP(j,m) {
    if (t[i][j] == '#') {
      uf.merge(i, n+j);
    }
  }
  bool ok = true;
  int wrows = 0;
  REP(i,n) {
    bool found = false;
    bool finish = false;
    REP(j,m) {
      if (t[i][j] == '#') {
        found = true;
        if (finish) ok = false;
      } else {
        if (found) finish = true;
      }
    }
    if (!found) ++wrows;
  }
  int wcols = 0;
  REP(i,m) {
    bool found = false;
    bool finish = false;
    REP(j,n) {
      if (t[j][i] == '#') {
        found = true;
        if (finish) ok = false;
      } else {
        if (found) finish = true;
      }
    }
    if (!found) ++wcols;
  }
  if ((wrows>0) != (wcols>0)) ok = false;
  if (!ok) {
    cout<<-1<<endl;
    return 0;
  }
  set<int> roots;
  REP(i,n+m) roots.insert(uf.root(i));
  cout<<roots.size()-wrows-wcols<<endl;
  return 0;
}
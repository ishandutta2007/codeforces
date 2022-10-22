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
  vecint lower;
  vecint upper;
  UnionFind (int n) : parent(n, -1), lower(n), upper(n) {
    REP(i,n) {
      lower[i] = upper[i] = i;
    }
  }
  int root(int x) { return parent[x] < 0 ? x : parent[x] = root(parent[x]); }
  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (parent[y] < parent[x]) swap(x, y);
    if (parent[x] == parent[y]) --parent[x];
    parent[y] = x;
    lower[x] = min(lower[x], lower[y]);
    upper[x] = max(upper[x], upper[y]);
    return true;
  }
};

int main()
{
  int n,m;
  cin>>n>>m;
  UnionFind uf(n);
  REP(i,m) {
    int a,b;
    cin>>a>>b;
    --a;--b;
    uf.merge(a, b);
  }
  vecint imos(2*n+1, 0);
  set<int> s;
  REP(i,n) {
    int r=uf.root(i);
    s.insert(r);
    --imos[2*uf.upper[r]+1];
    ++imos[2*uf.lower[r]];
  }
  int conti = s.size();
  int rem = 0;
  REP(i,2*n) {
    imos[i+1] += imos[i];
    if (imos[i] > 0 && imos[i+1] == 0) {
      ++rem;
    }
  }
  cout<<conti-rem<<endl;
  return 0;
}
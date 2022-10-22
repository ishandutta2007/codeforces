#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 n,m;
  cin>>n>>m;
  constexpr i32 INF = 1e9;
  vector mat(n, vi32(n, INF));
  rep(i,n) mat[i][i] = 0;
  UnionFind uf(2*n);
  rep(i,m) {
    i32 x,y,b;
    cin>>x>>y>>b;
    --x;--y;
    uf.merge(x, y+n);
    uf.merge(y, x+n);
    if (b == 0) {
      mat[x][y] = 1;
      mat[y][x] = 1;
    } else {
      mat[x][y] = 1;
      mat[y][x] = -1;
    }
  }
  if (uf.root(0) == uf.root(n)) {
    cout<<"NO"<<endl;
    return 0;
  }
  rep(k,n)rep(i,n)rep(j,n) {
    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
  }
  i32 ans = -1;
  i32 s = -1;
  rep(i,n)rep(j,n) {
    if (i == j && mat[i][i] < 0) {
      cout<<"NO"<<endl;
      return 0;
    }
    if (mat[i][j] > ans) {
      ans = mat[i][j];
      s = i;
    }
  }
  cout<<"YES"<<endl;
  cout<<ans<<endl;
  rep(i,n) {
    if (i) cout<<" ";
    cout<<mat[s][i];
  }
  cout<<endl;
  return 0;
}
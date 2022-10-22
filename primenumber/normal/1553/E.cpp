#include <bits/stdc++.h>
#include <variant>

#define rep2(i,k,n) for(i64 i=(i64)(k);i<(i64)(n);i++)
#define rep(i,n) rep2(i,0,n)
#define all(x) begin(x),end(x)
#ifdef ENV_LOCAL
#define dump if (1) cerr
#else
#define dump if (0) cerr
#endif

using namespace std;
using namespace std::string_literals;

using i32 = int32_t;
using i64 = int64_t;
using f64 = double;
using f80 = long double;
using vi32 = vector<i32>;
using vi64 = vector<i64>;

//using namespace harudake;

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
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,m;
    cin>>n>>m;
    vi32 hist(n);
    vi32 vp(n);
    rep(i,n) {
      i32 p;
      cin>>p;
      vp[i] = p-1;
      i32 k = (i+1+n-p) % n;
      ++hist[k];
    }
    i32 mnrem = n - 2*m;
    vi32 candi;
    rep(i,n) {
      if (hist[i] >= mnrem) {
        UnionFind uf(n);
        i32 cnt = n;
        rep(j,n) {
          i32 pj = (j+n-i) % n;
          if (uf.merge(pj,vp[j])) --cnt;
        }
        i32 need = n - cnt;
        //dump<<n<<" "<<cnt<<" "<<need<<" "<<m<<endl;
        if (need <= m) {
          candi.push_back(i);
        }
      }
    }
    cout<<size(candi);
    for(auto&&c:candi){
      cout<<" "<<c;
    }
    cout<<"\n";
  }
  return 0;
}
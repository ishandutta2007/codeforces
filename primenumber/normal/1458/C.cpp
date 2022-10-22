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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,m;
    cin>>n>>m;
    vector vmat(6, vector(n, vi32(n)));
    auto& mat = vmat[0];
    rep(i,n)rep(j,n) {
      cin>>mat[i][j];
      --mat[i][j];
    }
    rep(i,n)rep(j,n) {
      vmat[1][i][vmat[0][i][j]] = j; // 0 I
    }
    rep(i,n)rep(j,n) {
      vmat[3][vmat[1][i][j]][j] = i; // 1 C
    }
    rep(i,n)rep(j,n) {
      vmat[5][vmat[0][i][j]][j] = i; // 0 C
    }
    rep(i,n)rep(j,n) {
      vmat[2][i][vmat[3][i][j]] = j; // 3 I
    }
    rep(i,n)rep(j,n) {
      vmat[4][i][vmat[5][i][j]] = j; // 5 I
    }
    i32 x = 0, y = 0;
    i32 o = 0;
    i32 idx = 0;
    string q;
    cin>>q;
    auto sy = [] (int idx) {
      switch (idx) {
        case 0: return 5;
        case 1: return 3;
        case 2: return 4;
        case 3: return 1;
        case 4: return 2;
        case 5: return 0;
      }
      return 0;
    };
    rep(i,m) {
      switch (q[i]) {
        case 'R': x--; break;
        case 'L': x++; break;
        case 'D': y--; break;
        case 'U': y++; break;
        case 'I': idx ^= 1; swap(x, o); break;
        case 'C': idx = sy(idx); swap(y, o); break;
      }
    }
    x %= n;
    y %= n;
    o %= n;
    if (x < 0) x += n;
    if (y < 0) y += n;
    if (o < 0) o += n;
    rep(i,n){
      rep(j,n) {
        if (j)cout<<" ";
        i32 xij = x + j;
        i32 yij = y + i;
        if (xij < 0) xij += n;
        if (yij < 0) yij += n;
        xij %= n;
        yij %= n;
        cout<<(vmat[idx][yij][xij]+n-o)%n+1;
      }
      cout<<"\n";
    }
    if (t)cout<<"\n";
  }
  return 0;
}
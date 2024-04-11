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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  i32 t;
  cin>>t;
  while(t--) {
    i32 n,m;
    cin>>n>>m;
    vector<string> mat(n);
    rep(i,n) cin>>mat[i];
    using T = vector<pair<i32,i32>>;
    vector<T> ans;
    rep(i,n-2) {
      rep(j,m-1) {
        if (mat[i][j] == '1') {
          T tp;
          tp.emplace_back(i,j);
          tp.emplace_back(i+1,j);
          tp.emplace_back(i+1,j+1);
          ans.push_back(tp);
          mat[i][j] ^= 1;
          mat[i+1][j] ^= 1;
          mat[i+1][j+1] ^= 1;
        }
      }
      if (mat[i].back() == '1') {
        T tp;
        tp.emplace_back(i,m-1);
        tp.emplace_back(i+1,m-1);
        tp.emplace_back(i+1,m-2);
        ans.push_back(tp);
        mat[i][m-1] ^= 1;
        mat[i+1][m-1] ^= 1;
        mat[i+1][m-2] ^= 1;
      }
    }
    rep(j,m-2) {
      if (mat[n-1][j] == '1') {
        T tp;
        tp.emplace_back(n-1,j);
        tp.emplace_back(n-1,j+1);
        tp.emplace_back(n-2,j+1);
        ans.push_back(tp);
        mat[n-1][j] ^= 1;
        mat[n-1][j+1] ^= 1;
        mat[n-2][j+1] ^= 1;
      }
      if (mat[n-2][j] == '1') {
        T tp;
        tp.emplace_back(n-2,j);
        tp.emplace_back(n-1,j+1);
        tp.emplace_back(n-2,j+1);
        ans.push_back(tp);
        mat[n-2][j] ^= 1;
        mat[n-1][j+1] ^= 1;
        mat[n-2][j+1] ^= 1;
      }
    }
    rep(i,1<<4) {
      vector state(2, vector<bool>(2, false));
      rep(r,2)rep(c,2) {
        i32 idx = r*2 + c;
        if ((i>>idx)&1) {
          rep(r2,2)rep(c2,2) {
            if (r2 == r && c2 == c) continue;
            state[r2][c2] = !state[r2][c2];
          }
        }
      }
      bool ok = true;
      rep(r,2)rep(c,2) {
        i32 row = n-2 + r;
        i32 col = m-2 + c;
        bool is_one = mat[row][col] == '1';
        if (is_one != state[r][c]) ok = false;
      }
      if (ok) {
        rep(r,2)rep(c,2) {
          i32 idx = r*2 + c;
          if ((i>>idx)&1) {
            T tp;
            rep(r2,2)rep(c2,2) {
              if (r2 == r && c2 == c) continue;
              tp.emplace_back(n-2+r2, m-2+c2);
            }
            ans.push_back(tp);
          }
        }
        break;
      }
    }
    cout<<size(ans)<<endl;
    for(auto&&tp : ans) {
      rep(i,3) {
        if (i) cout<<" ";
        cout<<(tp[i].first+1)<<" "<<(tp[i].second+1);
      }
      cout<<"\n";
    }
  }
  return 0;
}
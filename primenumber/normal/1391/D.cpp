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
  vector<string> mat(n);
  REP(i,n) cin>>mat[i];
  if (n >= 4) {
    cout << -1 << endl;
    return 0;
  } else if (n < 2) {
    cout << 0 << endl;
    return 0;
  }
  vecint dp(1<<n);
  REP(i,1<<n) {
    int cnt = 0;
    REP(j,n) {
      bool is1 = mat[j][0] == '1';
      bool on = (i>>j)&1;
      if (is1 != on) ++cnt;
    }
    dp[i] = cnt;
  }
  REP(i,m-1) {
    vecint tmp(1<<n, n*m);
    REP(j,1<<n) {
      REP(k,2) {
        int cur = k;
        int cst = 0;
        int nx = 0;
        REP(x,n) {
          bool is1 = mat[x][i+1] == '1';
          bool on = cur == 1;
          if (is1 != on) ++cst;
          nx |= cur << x;
          if (x < n-1) {
            int sum = cur;
            sum += (j >> x)&1;
            sum += (j >> (x+1)) & 1;
            cur = 1 - sum % 2;
          }
        }
        tmp[nx] = min(tmp[nx], dp[j] + cst);
      }
    }
    swap(tmp, dp);
  }
  cout<<*min_element(ALL(dp))<<endl;
  return 0;
}
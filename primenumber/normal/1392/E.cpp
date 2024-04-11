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
  cin.tie(nullptr);
  ll n;
  cin>>n;
  vector mat(n, vecll(n, 0));
  REP(x,n)REP(y,n) {
    ll s = x+y;
    ll bit = 1ll << s;
    if (x % 2 == 1) mat[x][y] = bit;
  }
  REP(i,n) {
    REP(j,n) {
      if(j)cout<<" ";
      cout<<mat[i][j];
    }
    cout<<endl;
  }
  int q;
  cin>>q;
  REP(qcnt,q) {
    ll val;
    cin>>val;
    ll cx = 0;
    ll cy = 0;
    cout<<(cx+1)<<" "<<(cy+1)<<endl;
    REP(i,2*n-2) {
      ll ns = cx + cy + 1;
      bool nx_odd = ((val >> ns) & 1) == 1;
      bool cx_odd = cx % 2;
      if (nx_odd != cx_odd) {
        ++cx;
      } else {
        ++cy;
      }
      cout<<(cx+1)<<" "<<(cy+1)<<endl;
    }
  }
  return 0;
}
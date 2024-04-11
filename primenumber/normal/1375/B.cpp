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
  int t;
  cin>>t;
  REP(cnum,t) {
    int n,m;
    cin>>n>>m;
    vector mat(n, vecint(m));
    bool ok = true;
    REP(i,n)REP(j,m) {
      int a;
      cin>>a;
      int cnt = 0;
      if (i > 0) ++cnt;
      if (j > 0) ++cnt;
      if (i < n-1) ++cnt;
      if (j < m-1) ++cnt;
      if (a > cnt) ok = false;
      mat[i][j] = cnt;
    }
    if (!ok) {
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
      REP(i,n) {
        REP(j,m) {
          if(j)cout<<" ";
          cout<<mat[i][j];
        }
        cout<<"\n";
      }
    }
  }
  return 0;
}
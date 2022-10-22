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
  REP(cnum,t){
    int n,m;
    cin>>n>>m;
    vector<string> mat(n);
    REP(i,n) cin>>mat[i];
    int cnt = 0;
    REP(i,n-1) {
      if (mat[i][m-1] == 'R') ++cnt;
    }
    REP(i,m-1) {
      if (mat[n-1][i] == 'D') ++cnt;
    }
    cout<<cnt<<"\n";
  }
  return 0;
}
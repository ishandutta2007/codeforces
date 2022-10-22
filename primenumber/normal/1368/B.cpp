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
  ll k;
  cin>>k;
  vecint ary(10, 1);
  string cf = "codeforces";
  REP(i,64) {
    REP(j,10) {
      ll prod = 1;
      REP(x,10) {
        prod *= ary[x];
      }
      if (prod >= k) {
        REP(x,10) {
          REP(y,ary[x]) cout<<cf[x];
        }
        cout<<endl;
        return 0;
      }
      ++ary[j];
    }
  }
  return 0;
}
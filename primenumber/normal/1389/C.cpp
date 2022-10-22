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
    string s;
    cin>>s;
    int n = size(s);
    int mn = n;
    REP(i,10)REP(j,10) {
      int cnt = 0;
      for (auto&&c:s) {
        if (cnt%2 == 0) {
          if (c == '0' + i) ++cnt;
        } else {
          if (c == '0' + j) ++cnt;
        }
      }
      if (i != j) cnt -= cnt % 2;
      mn = min(mn, n - cnt);
    }
    cout<<mn<<"\n";
  }
  return 0;
}
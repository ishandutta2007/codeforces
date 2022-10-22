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
    int l,r;
    cin>>l>>r;
    if (l <= r/2) {
      cout << l << " " << l*2 << "\n";
    } else {
      cout << -1 << " " << -1 << "\n";
    }
  }
  return 0;
}
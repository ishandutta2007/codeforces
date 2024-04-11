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
  ll t;
  cin>>t;
  REP(cnum,t) {
    ll a,b,n;
    cin>>a>>b>>n;
    if (a < b) swap(a, b);
    REP(i,100) {
      if (a > n) {
        cout<<i<<"\n";
        break;
      }
      b += a;
      swap(a, b);
    }
  }
  return 0;
}
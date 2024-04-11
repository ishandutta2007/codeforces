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
  int t;
  cin>>t;
  REP(cnum,t) {
    ll n,k;
    cin>>n>>k;
    vecll a(n);
    REP(i,n) cin>>a[i];
    ll mx = *max_element(ALL(a));
    REP(i,n) a[i] = mx - a[i];
    --k;
    if (k % 2 == 1) {
      ll mx = *max_element(ALL(a));
      REP(i,n) a[i] = mx - a[i];
    }
    REP(i,n) {
      if(i)cout<<" ";
      cout<<a[i];
    }
    cout<<"\n";
  }
  return 0;
}
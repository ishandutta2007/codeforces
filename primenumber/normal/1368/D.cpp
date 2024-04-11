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
  ll n;
  cin>>n;
  vecint cnt(20);
  vecll ary(n);
  REP(i,n) {
    int x;
    cin>>x;
    REP(j,20) {
      if ((x>>j)&1) {
        ary[cnt[j]] |= 1 << j;
        ++cnt[j];
      }
    }
  }
  ll ans = 0;
  REP(i,n) {
    ans += ary[i] * ary[i];
  }
  cout<<ans<<"\n";
  return 0;
}
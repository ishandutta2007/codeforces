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
    ll n,k;
    cin>>n>>k;
    ll l1,r1;
    cin>>l1>>r1;
    ll l2,r2;
    cin>>l2>>r2;
    if (l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    ll d1 = 0;
    ll ov = 0;
    if (r1 < l2) {
      d1 = l2 - r1;
    } else {
      ov = min(r1, r2) - l2;
      k -= ov * n;
      k = max((ll)0, k);
    }
    ll rg = max(r1, r2) - min(l1, l2);
    ll d2 = 2*rg - (r1 - l1) - (r2 - l2);
    //ll h = d2 - d1;
    ll h2 = rg - ov;
    if (h2 == 0) {
      cout << 2*k << "\n";
    } else {
      ll dk = min(n, k / h2);
      ll rk = k - dk * h2;
      ll rem;
      if (dk == n) {
        rem = 2 * rk;
      } else if (dk == 0) {
        rem = d1 + rk;
      } else {
        rem = min(2 * rk, d1 + rk);
      }
      cout << (dk * d2 + rem) << "\n";
    }
  }
  return 0;
}
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
  ll d,n,m;
  cin>>n>>d>>m;
  vecll small, large;
  REP(i,n){
    ll a;
    cin>>a;
    if (a>m) {
      large.push_back(a);
    } else {
      small.push_back(a);
    }
  }
  sort(ALL(small),greater<>());
  ll k = size(small);
  sort(ALL(large),greater<>());
  ll l = size(large);
  vecll psl(l+1);
  partial_sum(ALL(large), begin(psl)+1);
  if (l == 0) {
    ll sum = 0;
    REP(i,k) sum += small[i];
    cout<<sum<<"\n";
    return 0;
  }
  ll mx = 0;
  ll sums = 0;
  REP(i,k+1) {
    auto rem = n - i;
    auto takel = (rem + d) / (d+1);
    if (takel <= l) {
      mx = max(mx, sums + psl[takel]);
    }
    if (i < k) sums += small[i];
  }
  cout<<mx<<"\n";
  return 0;
}
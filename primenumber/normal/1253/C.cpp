#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  ll n,m;
  cin>>n>>m;
  vecll a(n);
  REP(i,n) cin>>a[i];
  sort(ALL(a));
  vecll up(n);
  REP(i,n) {
    if (i >= m) {
      up[i] = a[i] + up[i-m];
    } else {
      up[i] = a[i];
    }
  }
  vecll ans(n);
  partial_sum(ALL(up),begin(ans));
  REP(i,n) {
    if (i) cout<<' ';
    cout<<ans[i];
  }
  cout<<endl;
  return 0;
}
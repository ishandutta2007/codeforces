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
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  REP(j,t) {
    ll n,k;
    cin>>n>>k;
    bool ok = true;
    if (n < k*k) ok = false;
    ll rem = n - k*k;
    if (rem % 2) ok = false;
    cout << (ok ? "YES" : "NO") << '\n';
  }
  cout<<flush;
  return 0;
}
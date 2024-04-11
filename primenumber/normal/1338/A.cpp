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
  REP(casenum,t) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n)cin>>a[i];
    int mx = -1e9;
    int cost = 0;
    REP(i,n) {
      if (a[i] < mx) {
        int d = mx - a[i];
        int cnt = 0;
        while (d) {
          ++cnt;
          d /= 2;
        }
        cost = max(cost, cnt);
      } else {
        mx = a[i];
      }
    }
    cout<<cost<<"\n";
  }
  cout<<flush;
  return 0;
}
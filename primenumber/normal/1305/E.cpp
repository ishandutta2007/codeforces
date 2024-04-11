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
  int n,m;
  cin>>n>>m;
  vecint res;
  FOR(i,1,n+1) {
    int made = (i-1) / 2;
    if (made <= m) {
      res.push_back(i);
      m -= made;
    } else {
      int j = i + 2 * (made - m);
      res.push_back(j);
      m = 0;
    }
    if (m == 0) break;
  }
  if (m > 0) {
    cout<<-1<<endl;
    return 0;
  }
  int rem = n - res.size();
  int step = 2*n;
  REP(i,rem) {
    res.push_back(1000000000 - (n - i) * step);
  }
  REP(i,n) {
    if(i)cout<<' ';
    cout<<res[i];
  }
  cout<<endl;
  return 0;
}
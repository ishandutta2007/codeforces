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
  int n;
  cin>>n;
  if(n%2) {
    cout<<"NO"<<endl;
    return 0;
  }
  vecint vx(n), vy(n);
  REP(i,n) {
    cin>>vx[i]>>vy[i];
  }
  bool ok = true;
  REP(i,n) {
    int ni = (i+1)%n;
    int oi = (i+n/2)%n;
    int noi = (oi+1)%n;
    int dx = vx[ni] - vx[i];
    int odx = vx[noi] - vx[oi];
    int dy = vy[ni] - vy[i];
    int ody = vy[noi] - vy[oi];
    if (dx + odx != 0 || dy + ody != 0) ok = false;
  }
  if (ok) {
    cout<<"YES"<<endl;
  } else {
    cout<<"NO"<<endl;
  }
  return 0;
}
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
  int n,m,k;
  cin>>n>>m>>k;
  REP(i,k) {
    int x,y;
    cin>>x>>y;
  }
  REP(i,k) {
    int x,y;
    cin>>x>>y;
  }
  cout<<n*m+n+m-3<<endl;
  REP(i,n-1) cout<<'U';
  REP(i,m-1) cout<<'L';
  REP(i,n) {
    REP(j,m-1) {
      cout<<(i%2?'L':'R');
    }
    if (i < n-1) cout<<'D';
  }
  cout<<endl;
  return 0;
}
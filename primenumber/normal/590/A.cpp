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
  int n;
  cin>>n;
  vecint a(n+1);
  REP(i,n) cin>>a[i];
  a[n] = a[n-1];
  vecint d(n, 0);
  REP(i,n-1) {
    if (a[i] != a[i+1]) d[i] = 1;
  }
  vecint b = a;
  int old = -1;
  int mx = 0;
  REP(i,n) {
    if (d[i] == 0) {
      if (old != -1) {
        int diff = i - old;
        int h = diff / 2;
        mx = max(mx, h);
        REP(j,h) {
          b[old+1+j] = b[old];
          b[i-j-1] = b[i];
        }
      }
      old = -1;
    } else {
      if (old == -1) old = i;
    }
  }
  cout<<mx<<endl;
  REP(i,n){
    if(i)cout<<" ";
    cout<<b[i];
  }
  cout<<endl;
  return 0;
}
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
  int t;
  cin>>t;
  while(t--) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n)cin>>a[i];
    int sum = 0;
    REP(i,n) sum += a[i];
    sort(ALL(a));
    if (sum == 0) {
      cout<<"NO\n";
      continue;
    } else if (sum > 0) {
      reverse(ALL(a));
    }
    cout<<"YES\n";
    REP(i,n) {
      if(i)cout<<" ";
      cout<<a[i];
    }
    cout<<"\n";
  }
  return 0;
}
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
  REP(cnum,t) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n)cin>>a[i];
    sort(ALL(a));
    if (a.front() == a.back()) {
      cout<<n<<"\n";
    }else{
      cout<<1<<"\n";
    }
  }
  return 0;
}
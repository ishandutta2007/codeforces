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
  REP(cnum,t) {
    int n;
    cin>>n;
    vecint hist(n, 0);
    REP(i,n) {
      int a;
      cin>>a;
      a %= n;
      ++hist[(i+n+a)%n];
    }
    if (count(ALL(hist),0) == 0) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }
  return 0;
}
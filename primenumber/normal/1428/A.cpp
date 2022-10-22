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
    ll x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    if (x1 == x2) {
      cout << abs(y1 - y2) << "\n";
    } else if (y1 == y2) {
      cout << abs(x1 - x2) << "\n";
    } else {
      cout << (abs(x1 - x2) + abs(y1 - y2) + 2) << "\n";
    }
  }
  return 0;
}
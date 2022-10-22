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
  while (t--) {
    string s;
    cin>>s;
    int a = 0, b = 0;
    for (char ch : s) {
      if (ch == 'A') {
        ++a;
      } else {
        if (a > 0) {
          --a;
        } else if (b > 0) {
          --b;
        } else {
          ++b;
        }
      }
    }
    cout<<(a+b)<<endl;
  }
  return 0;
}
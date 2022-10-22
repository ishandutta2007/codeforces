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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vecint mode(k, -1);
    bool ok = true;
    REP(i,n) {
      char c = s[i];
      if (c == '0') {
        if (mode[i%k] == 1) {
          ok = false;
        }
        mode[i%k] = 0;
      } else if (c == '1') {
        if (mode[i%k] == 0) {
          ok = false;
        }
        mode[i%k] = 1;
      } else {
        // nothing to do
      }
    }
    int zero = 0, one = 0;
    REP(i,k) {
      if (mode[i] == 0) ++zero;
      else if (mode[i] == 1) ++one;
    }
    if (!ok || zero > k/2 || one > k/2) {
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
    }
  }
  return 0;
}
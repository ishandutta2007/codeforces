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
    string s;
    cin>>s;
    bool has_l = false, has_r = false;
    int cnt = 0;
    REP(i,n) {
      if (s[i] == '>') has_r = true;
      else if (s[i] == '<') has_l = true;
      int pi = (i+n-1) % n;
      if (s[i] == '-' || s[pi] == '-') ++cnt;
    }
    if (!has_l || !has_r) {
      cout<<n<<"\n";
    } else {
      cout<<cnt<<"\n";
    }
  }
  return 0;
}
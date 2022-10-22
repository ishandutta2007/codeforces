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
  vector<string> v(n);
  REP(i,n) cin>>v[i];
  sort(ALL(v), [](auto&&lhs, auto&&rhs) {
      return lhs + rhs < rhs + lhs;
  });
  REP(i,n) cout<<v[i];
  cout<<"\n";
  return 0;
}
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
  cin.tie(0);
  int n;
  cin>>n;
  vector<tuple<int,int>> vp;
  REP(i,n) {
    vp.emplace_back(2*i, -2);
    vp.emplace_back(2*i, -1);
    vp.emplace_back(2*i, 0);
    vp.emplace_back(2*i, 1);
    vp.emplace_back(2*i, 2);
    vp.emplace_back(2*i+1, 0);
    if (i%2) {
      vp.emplace_back(2*i+1, 2);
    } else {
      vp.emplace_back(2*i+1, -2);
    }
  }
  vp.emplace_back(-2, 0);
  vp.emplace_back(-2, 1);
  vp.emplace_back(-2, 2);
  vp.emplace_back(-1, 0);
  vp.emplace_back(-1, 2);
  vp.emplace_back(2*n, 0);
  if (n % 2) {
    vp.emplace_back(2*n, -2);
    vp.emplace_back(2*n, -1);
  } else {
    vp.emplace_back(2*n, 1);
    vp.emplace_back(2*n, 2);
  }
  cout<<size(vp)<<"\n";
  for(auto[x,y]:vp) {
    cout<<x<<" "<<y<<"\n";
  }
  return 0;
}
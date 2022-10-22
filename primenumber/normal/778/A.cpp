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
  string t,p;
  cin>>t>>p;
  int n=size(t);
  vecint a(n);
  for(auto&&e:a)cin>>e;
  int le = 0;
  int gt = n+1;
  while(gt - le > 1) {
    int mid = (gt + le) / 2;
    vector<bool> erased(n, false);
    REP(i,mid) {
      erased[a[i]-1] = true;
    }
    size_t idx = 0;
    REP(i,n) {
      if (idx >= size(p)) break;
      if (erased[i]) continue;
      if (t[i] == p[idx]) ++idx;
    }
    if (idx < size(p)) {
      gt = mid;
    } else {
      le = mid;
    }
  }
  cout<<le<<endl;
  return 0;
}
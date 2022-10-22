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
  vector<tuple<int,int>> vt;
  REP(i,n) {
    int x,y;
    cin>>x>>y;
    vt.emplace_back(x,y);
  }
  sort(ALL(vt));
  vecint a(n), b(n);
  vecint cnt(n+1, 0);
  int i = 0;
  for(auto&&[x,y]:vt) {
    a[i] = x;
    b[i] = y;
    int left = a[i] - b[i];
    int idx = lower_bound(begin(a), begin(a)+i, left) - begin(a);
    cnt[i+1] = cnt[idx] + 1;
    ++i;
  }
  cout<<n-*max_element(ALL(cnt))<<endl;
  return 0;
}
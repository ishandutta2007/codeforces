#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int mex(const vecint& v) {
  int n = size(v);
  vector<bool> ex(n);
  REP(i,n) {
    if (v[i] < n) {
      ex[v[i]] = true;
    }
  }
  return (find(ALL(ex), false) - begin(ex));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  REP(cnum,t) {
    int n;
    cin>>n;
    vecint a(n);
    REP(i,n) {
      cin>>a[i];
    }
    vecint ops;
    while (!is_sorted(ALL(a))) {
      int m = mex(a);
      if (m == n) {
        REP(i,n) {
          if (a[i] != i) {
            ops.push_back(i);
            a[i] = n;
            break;
          }
        }
      } else {
        ops.push_back(m);
        a[m] = m;
      }
    }
    cout<<size(ops)<<"\n";
    int k=size(ops);
    REP(i,k) {
      if(i)cout<<" ";
      cout<<(ops[i]+1);
    }
    cout<<"\n";
  }
  return 0;
}
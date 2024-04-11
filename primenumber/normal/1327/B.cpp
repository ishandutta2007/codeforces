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
  REP(cs,t) {
    int n;
    cin>>n;
    vector<bool> md(n, false);
    int nm = -1;
    REP(i,n) {
      int k;
      cin>>k;
      bool ok = false;
      REP(j,k) {
        int g;
        cin>>g;
        --g;
        if (!ok && !md[g]) {
          ok = true;
          md[g] = true;
        }
      }
      if (!ok && nm < 0) nm = i;
    }
    if (nm >= 0) {
      cout<<"IMPROVE\n";
      int idx = find(ALL(md), false) - begin(md);
      cout<<nm+1<<" "<<idx+1<<"\n";
    } else {
      cout<<"OPTIMAL\n";
    }
  }
  cout<<flush;

  return 0;
}
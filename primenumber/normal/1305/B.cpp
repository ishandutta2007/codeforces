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
  string s;
  cin>>s;
  int n=s.size();
  REP(i,n+1) {
    int cnto = 0;
    REP(j,i) {
      if(s[j] == '(') ++cnto;
    }
    int cntc = 0;
    FOR(j,i,n) {
      if(s[j] == ')') ++cntc;
    }
    if (cnto == cntc) {
      if (cnto == 0) {
        cout<<0<<endl;
      } else {
        cout<<1<<endl;
        vecint res;
        REP(j,i) {
          if(s[j] == '(') res.push_back(j);
        }
        FOR(j,i,n) {
          if(s[j] == ')') res.push_back(j);
        }
        int l=res.size();
        cout<<l<<endl;
        REP(j,l) {
          if(j) cout<<' ';
          cout<<res[j]+1;
        }
        cout<<endl;
      }
      return 0;
    }
  }
  return 0;
}
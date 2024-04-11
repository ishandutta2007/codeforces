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
  vector<vecint> cnt(26, vecint(n+1, 0));
  REP(i,n) {
    REP(j,26) {
      if(s[i] - 'a' == j) {
        cnt[j][i+1] = cnt[j][i] + 1;
      } else {
        cnt[j][i+1] = cnt[j][i];
      }
    }
  }
  int q;
  cin>>q;
  REP(qry,q) {
    int l,r;
    cin>>l>>r;
    --l;
    int vari=0;
    REP(i,26) {
      if (cnt[i][l] != cnt[i][r]) {
        ++vari;
      }
    }
    bool ok = vari >= 3;
    ok = ok || (vari == 2 && s[l] != s[r-1]);
    ok = ok || (r-l == 1);
    if (ok) {
      cout<<"Yes"<<'\n';
    } else {
      cout<<"No"<<'\n';
    }
  }
  cout<<flush;
  return 0;
}
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
  string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  int t;
  cin>>t;
  REP(cases,t){
    int r,c,k;
    cin>>r>>c>>k;
    vector<string> m(r);
    for(auto& l:m) cin>>l;
    int rcnt = 0;
    for(auto& l:m) for(auto c:l) {
      if (c=='R') ++rcnt;
    }
    int num = 0;
    int cnt = 0;
    vector<string> res(r, string(c, '.'));
    REP(i,r) {
      REP(j,c) {
        int idx = j;
        if ((i%2) == 1) {
          idx = c-j-1;
        }
        res[i][idx] = str[min(num, k-1)];
        if (m[i][idx] == 'R') {
          ++cnt;
          int th = rcnt / k;
          if (num < rcnt % k) {
            ++th;
          }
          if (cnt == th) {
            ++num;
            cnt = 0;
          }
        }
      }
    }
    for(auto&& l:res) {
      cout<<l<<'\n';
    }
  }
  cout<<flush;
  return 0;
}
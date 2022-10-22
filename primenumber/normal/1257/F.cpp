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
  int n;
  cin>>n;
  vecint a(n);
  for(auto& e:a) cin>>e;
  vector<tuple<string, int>> vh;
  REP(i,1<<15) {
    string s(n, ' ');
    REP(j,n) {
      int num = __builtin_popcount((a[j] >> 15) ^ i);
      s[j] = 'a' + num;
    }
    vh.emplace_back(s, i);
  }
  sort(ALL(vh));
  REP(i,1<<15) {
    string s(n, ' ');
    int th = __builtin_popcount((a[0] & 0x7FFF) ^ i);
    REP(j,n) {
      int num = __builtin_popcount((a[j] & 0x7FFF) ^ i);
      s[j] = 'a' + th - num;
    }
    REP(j,31) {
      auto itr = lower_bound(ALL(vh), make_tuple(s, 0));
      if (itr != end(vh)) {
        auto [str, xh] = *itr;
        if (str == s) {
          cout<<((xh<<15) + i)<<endl;
          return 0;
        }
      }
      REP(k,n) {
        s[k] += 1;
      }
    }
  }
  cout<<-1<<endl;
  return 0;
}
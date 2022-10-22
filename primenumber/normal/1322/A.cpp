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
  int n;
  cin>>n;
  string s;
  cin>>s;
  if(n%2) {
    cout<<-1<<endl;
    return 0;
  }
  int cnt = 0;
  int len = 0;
  bool ok = true;
  int cost = 0;
  REP(i,n) {
    if (s[i] == '(') {
      ++cnt;
    } else {
      --cnt;
    }
    ++len;
    if (cnt == 0) {
      if (!ok) {
        cost += len;
      }
      len = 0;
      ok = true;
    } else if (cnt < 0) {
      ok = false;
    }
  }
  if (cnt != 0) {
    cout<<-1<<endl;
  } else {
    cout<<cost<<endl;
  }
  return 0;
}
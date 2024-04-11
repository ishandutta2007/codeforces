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
  int d;
  cin>>d;
  set<int> s;
  set<int> inday;
  bool ok = true;
  int old = -1;
  stringstream ss;
  int cnt = 0;
  REP(i,d) {
    int a;
    cin>>a;
    if (a < 0) {
      a = -a;
      if (s.count(a)) {
        s.erase(a);
        if (s.empty()) {
          ss << i-old << '\n';
          old = i;
          ++cnt;
          inday.clear();
        }
      } else {
        ok = false;
      }
    } else {
      if (s.count(a)) {
        ok = false;
      } else if (inday.count(a)) {
        ok = false;
      } else {
        s.insert(a);
        inday.insert(a);
      }
    }
  }
  if (!s.empty()) {
    ok = false;
  }
  if (ok) {
    cout<<cnt<<endl;
    cout<<ss.str()<<flush;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}
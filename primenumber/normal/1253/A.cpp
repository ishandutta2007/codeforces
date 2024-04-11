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
  int t;
  cin>>t;
  REP(cases,t) {
    int n;
    cin>>n;
    vecint a(n), b(n);
    for(auto& e:a)cin>>e;
    for(auto& e:b)cin>>e;
    vecint d(n);
    REP(i,n) {
      d[i] = b[i]-a[i];
    }
    int num = -1;
    int state = 0;
    REP(i,n) {
      if (d[i] < 0) {
        state = -1;
      } else if (d[i] == 0) {
        if (state == 1) {
          state = 2;
        }
      } else {
        if (num == -1) {
          if (state == 0) {
            state = 1;
            num = d[i];
          } else {
            state = -1;
          }
        } else if (d[i] != num) {
          state = -1;
        } else if (state != 1) {
          state = -1;
        }
      }
    }
    if (state == -1) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
    }
  }
  return 0;
}
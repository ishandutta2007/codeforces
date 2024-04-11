#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  int t;
  cin>>t;
  REP(cases,t) {
    int x,y;
    cin>>x>>y;
    bool ok = true;
    if (x == 1) {
      ok = y == 1;
    } else if (x <= 3) {
      ok = y <= 3;
    }
    if (ok) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
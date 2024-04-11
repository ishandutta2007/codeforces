#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  int cnt = 0;
  int mn = 0;
  REP(i,n) {
    if (s[i] == '(') {
      ++cnt;
    } else {
      --cnt;
    }
    mn = min(mn, cnt);
  }
  if (cnt != 0) {
    cout<<"No"<<endl;
  } else if (mn < -1) {
    cout<<"No"<<endl;
  } else {
    cout<<"Yes"<<endl;
  }
  return 0;
}
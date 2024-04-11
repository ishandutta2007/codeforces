#include <bits/stdc++.h>

#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;

typedef vector<int> vecint;

int main()
{
  int n;
  cin>>n;
  int h=n/2;
  REP(i,n) {
    REP(j,n) {
      if(abs(i-h)+abs(j-h)<=h) cout<<'D';
      else cout<<'*';
    }cout<<endl;
  }
  return 0;
}
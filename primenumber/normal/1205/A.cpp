#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main()
{
  int n;
  cin>>n;
  if ((n%2) == 0) {
    cout<<"NO"<<endl;
    return 0;
  }
  cout<<"YES"<<endl;
  int parity = 0;
  vecint prim, scnd;
  REP(i,n) {
    int num = 2*i + parity + 1;
    int num2 = 2*i + (1-parity) + 1;
    prim.push_back(num);
    scnd.push_back(num2);
    parity = 1-parity;
  }
  REP(i,n) {
    if(i) cout<<' ';
    cout<<prim[i];
  }
  REP(i,n) {
    cout<<' '<<scnd[i];
  }
  cout<<endl;
  return 0;
}
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
    int n,x,a,b;
    cin>>n>>x>>a>>b;
    if(a>b) swap(a,b);
    int suba = min(a-1, x);
    a -= suba;
    x -= suba;
    int addb = min(n-b, x);
    b += addb;
    x -= addb;
    cout<<b-a<<endl;
  }
  return 0;
}
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
  ll n;
  cin>>n;
  vecll delta(9*100000, 0);
  ll offset = 4*100000;
  REP(i,n) {
    int b;
    cin>>b;
    int idx = i+1;
    delta[b - idx + offset] += b;
  }
  cout<<*max_element(ALL(delta))<<endl;
  return 0;
}
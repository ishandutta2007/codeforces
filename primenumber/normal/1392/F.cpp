#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin>>n;
  ll sum = 0;
  REP(i,n) {
    ll h;
    cin>>h;
    sum += h - i;
  }
  REP(i,n) {
    if(i)cout<<' ';
    ll h = sum / n;
    if (i < sum % n) ++h;
    cout<<(h+i);
  }
  cout<<"\n";
  return 0;
}
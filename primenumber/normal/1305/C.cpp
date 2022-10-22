#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int pm(int base, int index, int mod) {
  if (index == 0) return 1;
  if ((index % 2) == 1) return base * pm(base, index-1, mod) % mod;
  int h = pm(base, index/2, mod);
  return h * h % mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  if (n > m) {
    cout<<0<<endl;
    return 0;
  }
  vecint a(n);
  for(auto&& e:a) cin>>e;
  ll prod = 1;
  REP(i,n)REP(j,i) {
    prod *= abs(a[i] - a[j]);
    prod %= m;
  }
  cout<<prod<<endl;
  return 0;
}
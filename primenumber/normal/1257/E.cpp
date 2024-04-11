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
  int k1,k2,k3;
  cin>>k1>>k2>>k3;
  vecint a1(k1), a2(k2), a3(k3);
  for(auto& e:a1) cin>>e;
  for(auto& e:a2) cin>>e;
  for(auto& e:a3) cin>>e;
  sort(ALL(a1));
  sort(ALL(a2));
  sort(ALL(a3));
  int n=k1+k2+k3;
  vecint ab(n+1), bc(n+1);
  REP(i,n+1) {
    int j=i+1;
    auto idx1 = lower_bound(ALL(a1), j) - begin(a1);
    auto idx2 = lower_bound(ALL(a2), j) - begin(a2);
    auto idx3 = lower_bound(ALL(a3), j) - begin(a3);
    ab[i] = idx1 + k2 - idx2;
    bc[i] = idx2 + k3 - idx3;
  }
  REP(i,n) {
    ab[i+1] = max(ab[i+1], ab[i]);
    bc[n-i-1] = max(bc[n-i-1], bc[n-i]);
  }
  int mn = n;
  REP(i,n+1) {
    int sum = ab[i] + bc[i] - k2;
    mn = min(mn, n-sum);
  }
  cout<<mn<<endl;
  return 0;
}
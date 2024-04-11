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
  int n;
  cin>>n;
  vecint a(n);
  for(auto&& e:a)cin>>e;
  //int ans = 0;
  //REP(i,n)REP(j,i) ans ^= a[i] + a[j];
  //cout<<ans<<endl;
  int ans2 = 0;
  REP(i,25) {
    vecint tmp = a;
    int mask = (1 << (i+1)) - 1;
    for(auto&& e:tmp) e &= mask;
    sort(ALL(tmp));
    int p = n, q = n, r = n;
    ll cnt = 0;
    int th1 = 1 << i;
    int th2 = 2*th1, th3 = 3*th1;
    REP(j,n) {
      while (p > 0 && tmp[p-1] + tmp[j] >= th1) --p;
      while (q > 0 && tmp[q-1] + tmp[j] >= th2) --q;
      while (r > 0 && tmp[r-1] + tmp[j] >= th3) --r;
      int pj = min(j, p);
      int qj = min(j, q);
      int rj = min(j, r);
      cnt += qj - pj;
      cnt += j - rj;
    }
    if (cnt%2) ans2 |= th1;
  }
  cout<<ans2<<endl;
  return 0;
}
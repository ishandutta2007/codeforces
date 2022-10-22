#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x) begin(x),end(x)

using namespace std;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll gcd2(ll a,ll b) {
  return a>b?gcd(a,b):gcd(b,a);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  random_device rd;
  mt19937_64 mt(rd());
  REP(cs,t) {
    int n,m;
    cin>>n>>m;
    vecll zbt(n);
    for(auto&& e:zbt) {
      e = mt();
    }
    vecll c(n);
    for(auto&& e:c) cin>>e;
    vecll rz(n);
    REP(i,m) {
      int u,v;
      cin>>u>>v;
      --u;--v;
      rz[v] ^= zbt[u];
    }
    map<ll,ll> mp;
    REP(i,n) {
      mp[rz[i]] += c[i];
    }
    ll ans = 0;
    for(auto&& p:mp) {
      if (p.first == 0) continue;
      ans = gcd2(ans, p.second);
    }
    cout<<ans<<'\n';
  }
  cout<<flush;
  return 0;
}
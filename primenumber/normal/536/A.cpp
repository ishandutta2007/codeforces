#include <bits/stdc++.h>
#include <variant>
#define FOR(i,k,n) for(ll i=(k);i<(ll)(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(x) begin(x),end(x)
 
using namespace std;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a,b,n;
  cin>>a>>b>>n;
  REP(i,n) {
    ll l,t,m;
    cin>>l>>t>>m;
    if (a + b * (l-1) > t) {
      cout<<-1<<"\n";
      continue;
    }
    ll le = l;
    ll gt = 1000001;
    while (gt - le > 1) {
      ll mid = (gt + le) / 2;
      ll cnt = mid - l + 1;
      ll d = min(m, cnt);
      ll tri = mid * (mid-1) / 2 - (l-2) * (l-1) / 2;
      ll sum = cnt * a + tri * b;
      ll last = a + b * (mid - 1);
      if (last > t || sum > d * t) {
        gt = mid;
      } else {
        le = mid;
      }
    }
    cout<<le<<"\n";
  }
  return 0;
}
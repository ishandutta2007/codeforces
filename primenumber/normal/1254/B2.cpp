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
  vecll a(n);
  for(auto& e:a) cin>>e;
  ll sum = 0;
  for(ll e:a) sum += e;
  if (sum == 1) {
    cout<<-1<<endl;
    return 0;
  }
  ll mn = sum * n;
  vecll p;
  for(ll i=2;i*i <= sum;++i) {
    if (sum % i == 0) {
      p.push_back(i);
      while (sum % i == 0) sum /= i;
    }
  }
  if (sum > 1) p.push_back(sum);
  for (ll d:p) {
    ll push = 0;
    ll pull = 0;
    ll rem = 0;
    for(ll e:a) {
      ll nrem = (e + rem) % d;
      if (e + rem - d < 0) {
        ll npush = push + nrem;
        ll npull = min(push, pull) + (d - nrem) % d;
        push = npush;
        pull = npull;
      } else {
        ll npush = min(push, pull) + nrem;
        ll npull = min(push, pull) + (d - nrem) % d;
        push = npush;
        pull = npull;
      }
      rem = nrem;
    }
    mn = min(mn, push);
  }
  cout<<mn<<endl;
  return 0;
}
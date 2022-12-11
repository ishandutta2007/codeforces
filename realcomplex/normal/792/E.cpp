#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> li;

ll solve(ll l1, ll l2){
  if(l1 == 0) return (ll)1e18;
  ll y;
  ll d;
  ll cur = 0;
  for(int i = 0; i < li.size(); i ++ ){
    y = li[i] % l2;
    d = li[i] / l2;
    if(y == 0 || y + d >= l1){
      cur += d;
      if(y != 0) cur ++ ;
    }
    else
      return (ll)1e18;
  }
  return cur;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  ll x;
  ll ans = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    li.push_back(x);
    ans += x;
  }
  sort(li.begin(), li.end());
  for(ll i = 1; i * i <= li[0]; i ++ ){
    ans = min(ans, solve(li[0]/i,li[0]/i + 1));
    ans = min(ans, solve((li[0]/i) - 1,(li[0]/i)));
    ans = min(ans, solve(i,i+1));
    if(i > 1) ans = min(ans, solve(i-1,i));
  }
  cout << ans << "\n";
  return 0;
}
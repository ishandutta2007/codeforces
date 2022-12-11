#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = (int)1e5 + 9;
const int LOG = 50;
ll a[LOG], b[LOG];
ll t[LOG];
ll ee[LOG];

bool can(ll k){
  for(ll i = 0 ; i < LOG; i++ )
    t[i] = 0, ee[i] = 0;
  ll cur = k;
  for(ll i = 0 ; i < LOG; i ++ ){
    cur = min(cur, a[i]);
    t[i] = cur;
    ee[i] = cur;
  }
  for(ll i = 0 ; i + 1 < LOG; i ++ ){
    ee[i] -= ee[i + 1];
  }
  ll sum = 0;
  for(ll i = LOG - 2; i >= 0 ; i -- ){
    sum -= a[i+1] - t[i+1];
    sum -= b[i];
    sum += ee[i];
    if(sum < 0) {
      return false;
    }    
  }
  sum -= a[0] - t[0];
  if(sum < 0) return false;
  return true;
}

int main(){
  fastIO;
  int n;
  cin >> n;
  ll x;
  bool ok;
  ll t;
  for(ll i = 1; i <= n; i ++ ){
    cin >> x;
    t = -1;
    for(ll j = 0 ; j < LOG;j ++ )
      if((x&(1ll<<j)))t=j;
    if((1ll<<t)==x){
      a[t] ++ ;
    }
    else{
      b[t] ++ ;
    }
  }
  vector<ll> pp;
  for(ll i = 1; i <= a[0]; i ++ )
    if(can(i)) pp.push_back(i);
  if(pp.empty()) cout << -1 << "\n";
  else for(auto x : pp) cout << x << " ";
  return 0;
}
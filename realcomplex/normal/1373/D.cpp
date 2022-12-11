#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll inf = (ll)1e18;
ll dp[3];

void upd(ll &a, ll b){  
  a = max(a, b);
}

void solve(){
  int n;
  cin >> n;
  ll sum = 0;
  ll ans = 0;
  dp[0]=0;
  dp[1]=-inf;
  dp[2]=-inf;
  ll a;
  ll sign = 0;
  for(int i = 0; i < n; i ++ ){
    cin >> a;
    if(i % 2 == 0) sum += a, sign = -1;
    else sign = +1;
    ll pa = dp[1], pb = dp[2];
    dp[1]=pb+sign*a;
    dp[2]=pa+sign*a;
    upd(dp[1],dp[0]+sign*a);
    ans = max(ans, dp[2]);
  }
  cout << sum + ans << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t =0 ; t < tc; t ++ )
    solve();
  return 0; 
}
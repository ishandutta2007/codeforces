#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
  int n;
  ll x;
  cin >> n >> x;
  vector<ll> a(n);
  ll res = (ll)1e18;
  for(int i = 0 ; i < n ; i ++ ){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  for(int i = 0 ; i < n; i ++ ){
    if(a[i] <= x){
      res = min((x + a[i] - 1) / a[i], res);
    }
    else{
      res = min((a[i] - x + a[i] - 1) / a[i] + 1, res);
    }
  }
  cout << res << "\n";
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ; t < tc; t ++ )
    solve();
  return 0;
}
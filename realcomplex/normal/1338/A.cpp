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
  cin >> n;
  vector<ll> a(n);
  for(int i = 0 ; i < n ; i ++ )
    cin >> a[i];
  ll mx = 0;
  ll lef = a[0];
  for(int i = 1 ; i < n; i ++ ){
    mx = max(mx, lef - a[i]);
    lef = max(lef, a[i]);
  }
  for(int i = 0 ; i < 35; i ++ ){
    if(mx <= 0){
      cout << i << "\n";
      return;
    }
    mx -= (1ll << i);
  }
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int i = 1; i <= tc; i ++ ){
    solve();
  }
  return 0;
}
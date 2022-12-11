#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)


void solve(){ 
  ll n, g, b;
  cin >> n >> g >> b;
  ll l = 0, r = (ll)3e18;
  ll md;
  ll good;
  while(l < r){
    md = (l + r) / 2ll;
    good = (md / (g + b)) * g + min(g, md % (g + b));
    if(good >= (n+1)/2ll && md >= n)
      r = md;
    else
      l = md + 1;
  }
  cout << r << "\n";
    
}

int main(){ 
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0; t < tc; t ++ ){  
    solve();
  }
  return 0;
}
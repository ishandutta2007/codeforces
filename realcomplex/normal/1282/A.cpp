#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

ll inter(pii a, pii b){
  return max(0ll, min(a.se,b.se)-max(a.fi,b.fi));
}

int main(){
  int tc;
  cin >> tc;
  for(int ff = 0; ff < tc; ff ++ ){
    ll a, b, c, r;
    cin >> a >> b >> c >> r;
    ll li = c - r;
    ll ri = c + r;
    if(a > b)
      swap(a, b);
    cout << (b-a)-inter(mp(a,b),mp(li,ri)) << "\n";
  }
  return 0;
}
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

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 1; t <= tc; t ++ ){
    ll x, y, p, q;
    cin >> x >> y >> p >> q;
    if(p == 0 && q == 1){
      if(x != 0){
        cout << "-1\n";
      }
      else{
        cout << 0 << "\n";
      }
    }
    else if(p == 1 && q == 1){
      if(x != y) cout << -1 << "\n";
      else cout << 0 << "\n";
    }
    else{
      y -= x;
      q -= p;
      ll l = 0, r = (ll)4e9;
      ll md;
      ll pt, qt;
      while(l < r){
        md = (l + r) / 2;
        pt = p * md;
        qt = q * md;
        if(pt >= x && qt >= y) r = md;
        else l = md + 1;
      }
      cout << (r * p - x) + (r * q - y) << "\n";
    }
  }
  return 0;
}
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
typedef long double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  fastIO;
  int tc;
  cin >> tc;
  ll z;
  ll ans;
  for(int t = 0; t < tc; t ++ ){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(b >= a){
      cout << b << "\n";
    }
    else{
      a -= b;
      if(c <= d){
        cout << "-1\n";
      }
      else{
        z = a/(c-d);
        ans = z*c+b;
        if(a % (c-d) > 0){
          ans += c;
        }
        cout << ans << "\n";
      }
    }
  }
  return 0;
}
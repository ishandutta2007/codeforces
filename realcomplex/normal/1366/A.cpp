#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ){
    ll a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    ll p = min(b - a, a);
    ll ans = p;
    a -= p;
    b -= 2ll * p;
    if(a == b)
      ans += (a + b) / 3ll;
    cout << ans << "\n";
  }
  return 0;
}
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
  for(int t = 0; t < tc; t ++ ){
    ll a, b, n;
    cin >> a >> b >> n;
    ll ans = 0;
    while(max(a,b) <= n){
      if(a > b) swap(a, b);
      a+=b;
      ans ++ ;
    }
    cout << ans << "\n";
  }
  return 0;
}
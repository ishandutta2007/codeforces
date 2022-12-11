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
  for(int t = 0;t < tc;t ++ ){
    int n;
    cin >> n;
    ll ans = 0;
    int k = n/2;
    ll x = 1;
    ll p;
    for(int i = 1; i <= k ; i ++ ){
      p=4*x+4;
      ans+=p*1ll*i;
      x+=2;
    }
    cout << ans << "\n";
  }
  return 0;
}
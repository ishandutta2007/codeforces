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
  int q;
  cin >> q;
  for(int t =0 ;t < q; t ++ ){
    ll c, m, x;
    cin >> c >> m >> x;
    ll l = 0,r = (ll)1e9;
    ll md;
    ll tot;
    bool ok = false;
    while(l + 1 < r){
      md = (l + r) / 2;
      ok = true;
      if(md > c || md > m)
        ok = false;
      else{
        tot = (c-md) + (m-md) + x;
        if(tot < md) ok = false;
      }
      if(ok)
        l = md;
      else
        r = md;
    }
    cout << l << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const ll inf = (ll)4e16;

ll ab(ll x){
  return max(x,-x);
}

ll dd(pii a, pii b){
  return ab(b.fi-a.fi) + ab(b.se-a.se);
}

int main(){
  fastIO;
  ll x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  ll xs, ys, t;
  cin >> xs >> ys >> t;
  vector<pii> pp = {mp(x0,y0)};
  pii cur;
  while(1){
    cur = mp(pp.back().fi * ax + bx,pp.back().se * ay + by);
    if(cur.fi >= inf || cur.se >= inf) break;
    pp.push_back(cur);
  }
  int res = 0;
  int m = pp.size();
  ll dist;
  for(int i = 0 ; i < m; i ++ ){
    for(int j = 0; j <= i ; j ++ ){
      for(int k = i ; k < m ; k ++ ){
        dist = 0;
        dist += dd(mp(xs,ys), pp[i]);
        dist += dd(pp[k],pp[j]);
        dist += min(dd(pp[i], pp[j]), dd(pp[i], pp[k]));
        if(dist <= t){
          res = max(res, k - j + 1);
        }
      }
    }
  }
  cout << res;
  return 0;
}
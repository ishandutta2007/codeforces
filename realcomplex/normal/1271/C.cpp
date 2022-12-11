#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int ab(int x){
  return max(x,-x);
}

int dist(pii x, pii y){ 
  return ab(x.fi-y.fi)+ab(x.se-y.se);
}

int main(){
  fastIO;
  int n, sx, sy; 
  cin >> n >> sx >> sy;
  pii pp[n];
  for(int i = 0 ; i < n; i ++ )
    cin >> pp[i].fi >> pp[i].se;
  vector<pii> chk = {mp(sx+1,sy), mp(sx-1,sy), mp(sx,sy+1), mp(sx,sy-1)};
  int res = 0;
  pii ans;
  int cur;
  for(auto p : chk){
    cur = 0;
    for(int i = 0 ; i < n; i ++ )
      if(dist(mp(sx,sy), pp[i]) == dist(mp(sx,sy),p) + dist(p,pp[i])){
        cur ++ ;
      }
    if(cur > res){
      res = cur;
      ans = p;
    }
  }
  cout << res << "\n";
  cout << ans.fi << " " << ans.se << "\n";
  return 0;
}
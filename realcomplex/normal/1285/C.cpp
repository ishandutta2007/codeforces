#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

vector<pair<ll, int>> cp;

ll ans = (ll)1e18;
ll xi, yi;

void rec(vector<ll> p){
  if(p.size() < cp.size()){
    p.push_back(0);
    for(int i = 0; i <= cp[(int)p.size()-1].se; i ++ ){
      p[(int)p.size()-1] = i;
      rec(p);
    }
    return;
  }
  ll x = 1, y = 1;
  for(int i = 0 ; i < p.size(); i ++ ){
    for(int j = 0 ; j < p[i];j ++ ){
      x *= cp[i].fi;
    }
    if(p[i] != cp[i].se){
      for(int j = 0 ; j < cp[i].se;j ++ )
        y *= cp[i].fi;
    }
  }
  if(max(x,y) < ans){
    xi=x;
    yi=y;
  }
  ans = min(ans, max(x, y));
}

int main(){
  ll x;
  cin >> x;
  for(ll i = 2; i * i <= x; i ++ ){
    if(x % i == 0){
      cp.push_back(mp(i, 0));
      while(x % i == 0){
        x/=i;
        cp[(int)cp.size()-1].se++;
      }
    }
  }
  if(x != 1)
    cp.push_back(mp(x,1));
  rec({});
  cout << xi << " " << yi << "\n";
  return 0;
}
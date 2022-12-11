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
  int n;
  cin >> n;
  ld xu, yu, xv, yv;
  cin >> xu >> yu >> xv >> yv;
  ld xi, yi, sx, sy;
  ld L, R;
  vector<pair<ld, int>> sweep;
  for(int i = 0 ; i < n; i ++ ){
    cin >> xi >> yi >> sx >> sy;
    ld xlow, xhigh;
    ld ylow, yhigh;
    if(sx == 0){
      if(xi <= xu || xi >= xv){
        cout << -1;
        return 0;
      }
      xlow = 0, xhigh = (ld)1e10;
    }
    else if(sx > 0){
      if(xi > xv){
        cout << -1;
        return 0;
      }
      if(xi <= xu){
        xlow = (xu - xi)/sx;
        xhigh = (xv-xi)/sx;
      }
      else{
        xlow = 0.0;
        xhigh = (xv - xi)/sx;
      }
    }
    else{
      if(xi < xu){
        cout << -1;
        return 0;
      }
      if(xi >= xv){
        xlow = (xi - xv)/-sx;
        xhigh = (xi-xu)/-sx;
      }
      else{
        xlow = 0.0;
        xhigh = (xi - xu)/-sx;
      }
    }
    if(sy == 0){
      if(yi <= yu || yi >= yv){
        cout << -1;
        return 0;
      }
      ylow = 0, yhigh = (ld)1e10;
    }
    else if(sy > 0){
      if(yi > yv){
        cout << -1;
        return 0;
      }
      if(yi <= yu){
        ylow = (yu - yi)/sy;
        yhigh = (yv-yi)/sy;
      }
      else{
        ylow = 0.0;
        yhigh = (yv - yi)/sy;
      }
    }
    else{
      if(yi < yu){
        cout << -1;
        return 0;
      }
      if(yi >= yv){
        ylow = (yi - yv)/-sy;
        yhigh = (yi-yu)/-sy;
      }
      else{
        ylow = 0.0;
        yhigh = (yi - yu)/-sy;
      }
    }
    L = max(xlow,ylow);
    R = min(xhigh,yhigh);
    if(L > R){
      cout << -1;
      return 0;
    }
    sweep.push_back(mp(L,+1));
    sweep.push_back(mp(R,-1));
  }
  sort(sweep.begin(), sweep.end());
  int cnt = 0;
  for(auto x : sweep){
    cnt += x.se;
    if(cnt == n){
      cout << fixed << setprecision(10) << x.fi << "\n";
      return 0;
    }
  }
  cout << -1;
  return 0;
}
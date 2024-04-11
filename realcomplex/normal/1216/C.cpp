#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
  fastIO;
  ll xl[3], yl[3], xr[3], yr[3];
  for(int i = 0 ;i  < 3; i ++ )
    cin >> xl[i] >> yl[i] >> xr[i] >> yr[i];
  for(int i = 1; i < 3; i ++ ){
    xl[i] = max(xl[i], xl[0]);
    yl[i] = max(yl[i], yl[0]);
    xr[i] = min(xr[i], xr[0]);
    yr[i] = min(yr[i], yr[0]);
    xr[i] = max(xr[i], xl[i]);
    yr[i] = max(yr[i], yl[i]);
  }
  ll tot = (xr[0] - xl[0]) * (yr[0] - yl[0]);
  for(int i = 1; i < 3; i ++ ){
    tot -= (xr[i] - xl[i]) * (yr[i] - yl[i]);
  }
  ll L, R;
  L = min(xr[1], xr[2]) - max(xl[1], xl[2]);
  L = max(L,0ll);
  R = min(yr[1], yr[2]) - max(yl[1], yl[2]);
  R = max(R,0ll);
  tot += (L * R);
  if(tot > 0){
    cout << "YES\n";
  }
  else{
    cout << "NO\n";
  }
  return 0;
}
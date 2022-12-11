#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1000;
int grundy[N][3];
int mex[5];

void solve(){
  int n, x, y, z;
  cin >> n >> x >> y >> z;
  for(int i = 1; i < N; i ++ ){
    for(int j = 0 ; j < 3; j ++ ){
      for(int k = 0 ; k < 5 ; k ++ ) mex[k]=0;
      grundy[i][j] = 0;
      mex[grundy[max(0,i - x)][0]] = 1 ;
      if(j != 1) mex[grundy[max(0,i - y)][1]] = 1 ;
      if(j != 2) mex[grundy[max(0,i - z)][2]] = 1 ;
      while(mex[grundy[i][j]] > 0) grundy[i][j] ++ ;
    }
  }
  int cut = 100;
  bool ok;
  int per = -1;
  for(int len = 1; len < 100 ; len ++ ){
    ok = true;
    for(int i = cut; i + len < N ; i ++ ){
      if(grundy[i + len][0] != grundy[i][0]){
        ok = false;
        break;
      }
    }
    if(ok){
      per = len;
    }
  }
  assert(per != -1);
  vector<ll> qq(n);
  int xr = 0;
  for(int i = 0 ; i < n; i ++ ){
    cin >> qq[i];
    if(qq[i] <= cut){
      xr ^= grundy[qq[i]][0];
    }
    else{
      qq[i] = (qq[i] - cut) % per + cut;
      xr ^= grundy[qq[i]][0];
    }
  }
  if(xr == 0){
    cout << 0 << "\n";
  }
  else{
    int res = 0;
    for(int i = 0 ; i < n; i ++ ){
      if(grundy[max(0ll,qq[i] - x)][0] == (xr ^ grundy[qq[i]][0])) res ++ ;
      if(grundy[max(0ll,qq[i] - y)][1] == (xr ^ grundy[qq[i]][0])) res ++ ;
      if(grundy[max(0ll,qq[i] - z)][2] == (xr ^ grundy[qq[i]][0])) res ++ ;
    }
    cout << res << "\n";
  }
}

int main(){
  fastIO;
  int tc;
  cin >> tc;
  for(int t = 0 ;t < tc; t ++ ) solve();
  return 0;
}
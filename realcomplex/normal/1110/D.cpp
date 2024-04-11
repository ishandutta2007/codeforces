#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e6 + 100;
int dp[N][3][3];
int cnt[N];

int main(){
  fastIO;
  for(int i = 0 ; i < N ; i ++ )
    for(int x = 0 ; x < 3; x ++ ) for(int y = 0 ; y < 3; y ++ )
      dp[i][x][y] = -(int)1e9;
  int n, m;
  cin >> n >> m;
  int x;
  for(int i = 1; i <= n; i ++ ){
    cin >> x;
    cnt[x] ++ ;
  }
  for(int i = 0 ; i < 3; i ++ ){
    for(int j = 0 ; j < 3; j ++ ){
      if(cnt[1] >= i && cnt[2] >= i + j && cnt[3] >= i + j){
        dp[2][i][j] = ((cnt[1]-i)/3+(cnt[2]-i-j)/3) + i + j;
      }
    }
  }
  int nx;
  for(int i = 2; i < N - 50; i ++ ){
    for(int x = 0; x < 3; x ++ ){
      for(int y = 0 ;y < 3 ;y ++ ){
        for(int z = 0 ; z < 3 ; z ++ ){
          if(dp[i][x][y] == -(int)1e9) continue;
          if(cnt[i+1] >= x + y + z  && cnt[i+2] >= y+z && cnt[i+3] >= z){
            nx = dp[i][x][y];
            nx += z; 
            nx += (cnt[i+1] - x - y - z)/3;
            dp[i+1][y][z] = max(dp[i+1][y][z], nx);
          }
        }
      }
    }
  }
  int res = 0;
  for(int i = 0 ; i < N ; i ++ )
    for(int x = 0 ; x < 3; x ++ )
      for(int y = 0 ; y < 3; y ++ )
        res = max(res, dp[i][x][y]);
  cout << res << "\n";
  return 0;
}
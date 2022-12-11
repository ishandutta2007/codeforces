#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 79;
char s[N];
int dp[N][N][N][3];

void st(int &a, int b){
  a = min(a, b);
}

bool ban[N];

int main(){ 
  fastIO;
  int n;
  cin >> n;
  int cv = 0, ck = 0, ca = 0;
  for(int i = 1; i <= n; i ++ ){
    cin >> s[i];
    if(s[i] != 'V' && s[i] != 'K')
      s[i] = 'A';
    if(s[i] == 'V') cv ++ ;
    else if(s[i] == 'K') ck ++ ;
    else ca ++ ;
  }
  for(int i = 0 ; i <= n; i ++ ){
    for(int j = 0 ; j <= n; j ++ ){
      for(int k = 0 ; k <= n; k ++ ){
        for(int d = 0 ;d < 3; d ++ )
          dp[i][j][k][d] = (int)1e9;
      }
    }
  }
  dp[0][0][0][2] = 0;
  int cnt;
  bool ok;
  for(int i = 0 ; i <= cv; i ++ ){
    for(int j = 0; j <= ck ; j ++ ){
      for(int y = 0 ; y <= ca; y ++ ){
        for(int las = 0 ; las < 3; las ++ ){
          cnt = 0;
          for(int t = 1; t <= n; t ++ ){
            if(s[t] == 'V'){
              cnt ++ ;
              if(cnt <= i) ban[t] = true;
              else ban[t] = false;
            }
          }
          cnt = 0;
          for(int t = 1; t <= n; t ++ ){
            if(s[t] == 'K'){
              cnt ++ ;
              if(cnt <= j) ban[t] = true;
              else ban[t] = false;
            }
          }
          cnt = 0;
          for(int t = 1; t <= n; t ++ ){
            if(s[t] == 'A'){
              cnt ++ ;
              if(cnt <= y) ban[t] = true;
              else ban[t] = false;
            }
          }
          cnt = 0;
          ok = false;
          for(int t = 1; t <= n; t ++ ){
            if(!ban[t]){
              if(s[t] == 'V'){
                ok = true;
                break;
              }
              cnt ++ ;
            }
          }
          if(ok) st(dp[i+1][j][y][0],dp[i][j][y][las]+cnt);
          cnt = 0;
          ok = false;
          for(int t = 1; t <= n; t ++ ){
            if(!ban[t]){
              if(s[t] == 'K'){
                ok = true;
                break;
              }
              cnt ++ ;
            }
          }
          if(ok && las != 0) st(dp[i][j+1][y][1],dp[i][j][y][las]+cnt);
          cnt = 0;
          ok = false;
          for(int t = 1; t <= n; t ++ ){
            if(!ban[t]){
              if(s[t] == 'A'){
                ok = true;
                break;
              }
              cnt ++ ;
            }
          }
          if(ok) st(dp[i][j][y+1][2],dp[i][j][y][las]+cnt);
        }
      }
    }
  }
  cout << min({dp[cv][ck][ca][0],dp[cv][ck][ca][1],dp[cv][ck][ca][2]});
  return 0;
}
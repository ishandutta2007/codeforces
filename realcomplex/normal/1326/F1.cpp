#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 14;
const int M = 7;
ll dp[1 << N][1 << (M-1)][N];
bool know[N][N];
ll sol[1 << N];

int mbt[1 << M][1 << M][2];

int n, h;
void calc(int i, int j, int bt){
  vector<int> mask;
  for(int k = 0 ; k < h - 1; k ++ ){
    mask.push_back(min(1, (i&(1<<k))));
  }
  mask.push_back(bt);
  for(int k = n - h - 2; k >= 0 ; k -- ){
    mask.push_back(min(1, (j&(1<<k))));
  }
  int sum = 0;
  for(int i = 0 ; i < n-1; i ++ ){
    sum += mask[i]*(1<<i);
  }
  mbt[i][j][bt]=sum;
}

int main(){
  fastIO;
  cin >> n;
  h = (n+1)/2;
  char f;
  for(int i = 0 ; i < n; i ++ ){
    for(int j = 0 ; j < n; j ++ ){
      cin >> f;
      know[i][j]=f-'0';
    }
  }
  for(int i = 0 ; i < n; i ++ )
    dp[(1 << i)][0][i] = 1;
  int cnt;
  for(int i = 1; i < (1 << n); i ++ ){
    if(__builtin_popcount(i) + 1 > h) continue;
    cnt = __builtin_popcount(i) - 1;
    for(int j = 0 ; j < (1 << (h - 1)); j ++ ){
      for(int cur = 0 ; cur < n; cur ++ ){
        if(dp[i][j][cur] == 0) continue;
        for(int nx = 0 ; nx < n; nx ++ ){
          if((i & (1 << nx)) == 0){
            dp[(i|(1<<nx))][j|(know[cur][nx]*(1<<cnt))][nx] += dp[i][j][cur];
          }
        }
      }
    }
  }
  for(int i = 0 ; i < (1 << (h-1)); i ++ ){
    for(int j = 0 ; j < (1 << (n-h-1)); j ++ ){
      for(int q = 0; q < 2; q ++ ){
        calc(i,j,q);
      }
    }
  }
  int oth;
  int sum = 0;
  for(int i = 0 ; i < (1 << n); i ++ ){
    if(__builtin_popcount(i) == h){
      oth = (1 << n) - 1 - i;
      for(int j = 0 ; j < (1 << (h - 1)); j ++ ){
        for(int pv = 0; pv < n; pv ++ ){
          if(dp[i][j][pv]==0) continue;
          for(int x = 0 ; x < (1 << (n - h - 1)); x ++ ){
            if((i&(1<<pv))){
              for(int nx = 0; nx < n ; nx ++ ){
                if(dp[oth][x][nx]==0) continue;
                if((oth&(1<<nx))){
                  sum = mbt[j][x][know[pv][nx]];
                  sol[sum] += dp[i][j][pv]*1ll*dp[oth][x][nx];
                }
              }
            }
          }
        }
      }
    }
  }
  for(int i = 0 ; i < (1 << (n-1)) ; i ++ ){
    cout << sol[i] << " ";
  }
  return 0;
}
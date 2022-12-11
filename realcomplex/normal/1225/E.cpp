#include <bits/stdc++.h>

using namespace std;

const int N = 2005;
const int MOD = (int)1e9 + 7; 

int empR[N][N];
int empD[N][N];

int conf[N][N];

int dp[N][N][2]; 
int pfL[N][N];
int pfD[N][N];

// 0 - enter from Left
// 1 - enter from Up

void add(int &a, int b){
  b += MOD;
  b %= MOD;
  a = (a + b) % MOD;
}

int main(){
  int n, m;
  cin >> n >> m;
  char f;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      cin >> f;
      if(f == '.')
        conf[i][j] = 1;
      else
        conf[i][j] = 0;
    }
  }
  for(int i = 1; i <= n; i ++ ){
    for(int j = m ; j >= 1; j -- ){
      empR[i][j] = empR[i][j + 1] + conf[i][j];
    }
  }
  for(int i = n; i >= 1; i -- ){
    for(int j = 1; j <= m ; j ++ ){
      empD[i][j] = empD[i + 1][j] + conf[i][j];
    }
  }
  pfL[1][1] ++ ;
  pfL[1][empR[1][1] + 1] -- ;
  pfD[1][1] ++ ;
  pfD[empD[1][1] + 1][1] -- ;
  dp[1][1][0] = 1;
  for(int i = 1; i <= n; i ++ ){
    for(int j = 1; j <= m ; j ++ ){
      if(i==1 && j == 1) continue;
      add(pfL[i][j], pfL[i][j-1]);
      add(pfD[i][j], pfD[i-1][j]);
      dp[i][j][0] = pfL[i][j];
      dp[i][j][1] = pfD[i][j];
      add(pfL[i][j + 1], dp[i][j][1]);
      add(pfL[i][j + 1 + empR[i][j + 1]], -dp[i][j][1]);
      add(pfD[i + 1][j], dp[i][j][0]);
      add(pfD[i + 1 + empD[i + 1][j]][j], -dp[i][j][0]);
    }
  }
  cout << (dp[n][m][0] + dp[n][m][1]) % MOD;
  return 0;
}
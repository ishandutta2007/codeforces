#include <bits/stdc++.h>

using namespace std;

const int N = 211;
const int mod = 1e8;

int n, m, x, y;
int f[N][N][3];

int add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> n >> m >> x >> y;
  f[0][0][1] = 1;
  f[0][0][2] = 1;
  for(int i = 1; i <= n + m; ++i){
    for(int j = 0; j <= min(i, n); ++j){
      int k = i - j;
      if(k > m){
        continue;
      }
      for(int use = 1; use <= min(j, x); ++use){
        add(f[i][j][1], f[i - use][j - use][2]);
      }
      for(int use = 1; use <= min(y, k); ++use){
        add(f[i][j][2], f[i - use][j][1]);
      }
    }
  }
  cout << (f[n + m][n][1] + f[n + m][n][2]) % mod;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 211;
const long long mod = 1e9 + 7;

int n, k, d;
long long f[N][N][2];
long long answer;

void update(long long &u, long long v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d%d%d", &n, &k, &d);
  f[0][0][0] = 1;
  for(int i = 0; i <= n; ++i){
    for(int w = 0; w < n; ++ w){
      for(int c = 1; c <= k; ++c){
        update(f[i + 1][w + c][1], f[i][w][1]);
        int bigger = (c >= d);
        update(f[i + 1][w + c][bigger], f[i][w][0]);
      }
    }
    update(answer, f[i][n][1]);
  }
  cout << answer;
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 1111, M = 10000;
const double eps = 0.0000001;

int n, m;
double f[M][N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // pts
  scanf("%d%d", &n, &m);
  f[1][1] = 1;
  for(int i = 1; i < M - 1; ++i){
    for(int j = 1; j <= min(n, i); ++j){
      f[i + 1][j + 1] += f[i][j] * ((1.0 * (n - j)) / (1.0 * n));
      f[i + 1][j] += f[i][j] * ((1.0 * j) / (1.0 * n));
    }
  }
  while(m--){
    int val;
    scanf("%d", &val);
    for(int i = 1; i < M; ++i){
      if(f[i][n] >= (1.0 * val - eps) / (1.0 * 2000)){
        cout << i << endl;
        break;
      }
    }
  }
  return 0;
}
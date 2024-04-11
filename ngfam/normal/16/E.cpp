#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n;
double a[N][N];
double f[1 << N];

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  cin >> n;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j){
      cin >> a[i][j];
    }
  }
  cout << fixed << setprecision(6);
  f[(1 << n) - 1] = 1.0;
  for(int mask = (1 << n) - 1; mask > 0; --mask){
    if(__builtin_popcount(mask) == 1){
      continue;
    }
    int x = __builtin_popcount(mask);
    x = (x * (x - 1)) / 2;
    for(int i = 0; i < n; ++i){
      if((mask & (1 << i)) == 0){
        continue;
      }
      for(int j = i + 1; j < n; ++j){
        if((mask & (1 << j)) == 0){
          continue;
        }
        f[mask ^ (1 << i)] += f[mask] * a[j][i] * (1.0 / double(x));
        f[mask ^ (1 << j)] += f[mask] * a[i][j] * (1.0 / double(x));
      }
    }
  }
  for(int i = 0; i < n; ++i){
    cout << f[1 << i] << " ";
  }
  return 0;
}
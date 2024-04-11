#include <bits/stdc++.h>

using namespace std;

const int N = 2222;
const int mod = 1e9 + 7;

int n, k;
int f[N][N];

void add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; ++i){
    f[i][1] = 1;
  }
  for(int j = 1; j < k; ++j){
    for(int i = 1; i <= n; ++i){
      for(int x = i; x <= n; x += i){
        add(f[x][j + 1], f[i][j]);
      }
    }
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    add(answer, f[i][k]);
  }
  cout << answer;
  return 0;
}
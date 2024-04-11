#include <bits/stdc++.h>

using namespace std;

const int N = 5050;
const int mod = 1e9 + 7;

int n, k, a, b;
int f[N][N];
int s[N][N];

void add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
  while(u < 0){
    u += mod;
  }
}

void PreCalc(int i){
  for(int x = 1; x <= n; ++x){
    s[i][x]= s[i][x - 1] + f[i][x];
  }
}

void upd(int i, int x, int ins){
  x = max(x, 1);
  x = min(x, n + 1);
  add(s[i][x], ins);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d%d%d", &n, &a, &b, &k);
  s[0][a] = 1;
  s[0][a + 1] = -1;
  for(int i = 0; i < k; ++i){
    for(int u = 1; u <= n; ++u){
      add(f[i][u], s[i][u]);
      add(f[i][u], f[i][u - 1]);
    }
    for(int u = 1; u <= n; ++u){
      int dist = abs(u - b);
      upd(i + 1, u - dist + 1, f[i][u]);
      upd(i + 1, u, -f[i][u]);
      upd(i + 1, u + 1, f[i][u]);
      upd(i + 1, u + dist, -f[i][u]);
    }
  }
  int answer = 0;
  for(int i = 1; i <= n; ++i){
    add(f[k][i], f[k][i - 1] + s[k][i]);
    add(answer, f[k][i]);
  }
  cout << answer;
  return 0;
}
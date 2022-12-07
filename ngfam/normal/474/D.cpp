#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int mod = 1e9 + 7;

int f[N];

int sub(int u, int v){
  u -= v;
  if(u < 0){
    u += mod;
  }
  return u;
}

int add(int u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
  return u;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  int tt, k;
  scanf("%d%d", &tt, &k);
  f[0] = 1;
  for(int i = 1; i < N; ++i){
    f[i] = f[i - 1];
    if(i >= k){
      f[i] = add(f[i], f[i - k]);
    }
  }
  for(int i = 1; i < N; ++i){
    f[i] = add(f[i], f[i - 1]);
  }
  while(tt--){
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", sub(f[v], f[u - 1]));
  }
  return 0;
}
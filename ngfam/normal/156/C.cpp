#include <bits/stdc++.h>

using namespace std;

const int N = 110;
const int mod = 1e9 + 7;

int n, m;
int f[N][N * 26];

int add(int u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
  if(u < 0){
    u += mod;
  }
  return u;
}

int sub(int u, int v){
  u -= v;
  if(u < 0){
    u += mod;
  }
  return u;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  int tt;
  scanf("%d", &tt);
  f[0][0] = 1;
  for(int i = 1; i < N; ++i){
    for(int s = 0; s < N * 26; ++s){
      for(int c = 0; c <= min(25, s); ++c){
        f[i][s] = add(f[i][s], f[i - 1][s - c]);
      }
    }
  }
  while(tt--){
    char a[N];
    scanf("%s", a + 1);
    n = strlen(a + 1);
    int sum = 0;
    for(int i = 1; i <= n; ++i){
      sum += a[i] - 'a';
    }
    printf("%d\n", sub(f[n][sum], 1));
  }
  return 0;
}
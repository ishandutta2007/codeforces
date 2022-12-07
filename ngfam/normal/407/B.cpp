#include <bits/stdc++.h>

using namespace std;

const int N = 1010;
const int mod = 1e9 + 7;

int n;
int a[N];
int t[N];
int j[N];
int s[N];
int g[N];
int f[N];
int prefix[N];

void add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

void sub(int &u, int v){
  u -= v;
  if(u < 0){
    u += mod;
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  if(n == 1){
    cout << 2;
    return 0;
  }
  f[1] = 1;
  for(int i = 1; i <= n; ++i){
    add(f[i + 1], f[i]);
    add(f[i + 1], f[i]);
    add(f[i + 1], 2);
    sub(f[i + 1], f[a[i]]);
  }
  cout << f[n + 1] - 1;
  return 0;
}
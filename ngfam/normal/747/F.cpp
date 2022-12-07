#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int n, k;
int rem[N];
int ans[N];
long long c[N][N];
long long f[N][N];

long long add(long long u, long long v){
  u += v;
  if(u > n){
    u = n + 1;
  }
  return u;
}

long long mul(long long u, long long v){
  u *= v;
  if(u > n){
    u = n + 1;
  }
  return u;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &k);
  for(int i = 0; i < N; ++i){
    c[i][0] = 1;
    for(int j = 1; j <= i; ++j){
      c[i][j] = add(c[i - 1][j], c[i - 1][j - 1]);
    }
  }
  int last = 0;
  for(int len = 1; len < 20; ++len){
    memset(f, 0, sizeof f);
    f[0][0] = 1;
    for(int x = 1; x <= 16; ++x){
      for(int p = 0; p <= min(len, (x - 1) * k); ++p){
        for(int u = 0; u <= k; ++u){
          if(p + u > len){
            break;
          }
          f[x][p + u] = add(f[x][p + u], mul(c[max(0, len - p - (x == 1))][u], f[x - 1][p]));
        }
      }
    }
    if(f[16][len] >= n){
      last = len;
      break;
    }
    else{
      n -= f[16][len];
    }
  }
  for(int i = 1; i <= 16; ++i){
    rem[i] = k;
  }
  for(int i = 1; i <= last; ++i){
    for(int x = 1 + (i == 1); x <= 16; ++x){
      --rem[x];
      int len = last - i;
      memset(f, 0, sizeof f);
      f[0][0] = 1;
      int sum = 0;
      for(int r = 1; r <= 16; ++r){
        for(int p = 0; p <= min(len, sum); ++p){
          for(int u = 0; u <= min(len, rem[r]); ++u){
            if(p + u > len){
              break;
            }
            f[r][p + u] = add(f[r][p + u], mul(c[len - p][u], f[r - 1][p]));
          }
        }
        sum += rem[r];
      }
      if(f[16][len] >= n){
        ans[i] = x;
        break;
      }
      else{
        n -= f[16][len];
      }
      ++rem[x];
    }
  }
  for(int i = 1; i <= last; ++i){
    if(ans[i] <= 10){
      cout << char(ans[i] + '0' - 1);
    }
    else{
      cout << char(ans[i] + 'a' - 11);
    }
  }
  return 0;
}
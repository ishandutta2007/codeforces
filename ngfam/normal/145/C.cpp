#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 2020;
const long long mod = 1e9 + 7;

int n, k, m;
int a[N];
int slv[N];
int fine[N];
long long foo[N];
long long f[M][M];
long long answer = 0;

map < int, int > appear;

bool lucky(int x){
  if(x == 0){
    return 1;
  }
  int md = x % 10;
  if(md != 4 && md != 7){
    return 0;
  }
  return lucky(x / 10);
}

long long powmod(int x, int y){
  if(y == 0){
    return 1;
  }
  if(y == 1){
    return x;
  }
  long long calc = powmod(x, y >> 1);
  calc = (calc * calc) % mod;
  if(y & 1){
    calc = (calc * x) % mod;
  }
  return calc;
}

long long nCk(int x, int y){
  return (foo[x] * powmod((foo[y] * foo[x - y]) % mod, mod - 2)) % mod;
}

bool cmp(int u, int v){
  if(lucky(u) == lucky(v)){
    return u < v;
  }
  return lucky(u) > lucky(v);
}

long long divide(long long x, long long y){
  if(y == 0){
    return 1;
  }
  return (x * powmod(y, mod - 2)) % mod;
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d", &n, &k);
  foo[0] = 1;
  int cnt = 0;
  for(int i = 1; i <= n; ++i){
    foo[i] = (foo[i - 1] * i) % mod;
    scanf("%d", a + i);
    cnt += 1 - lucky(a[i]);
  }
  sort(a + 1, a + n + 1, cmp);
  for(int i = 1; i <= n; ++i){
    if(lucky(a[i]) == 0){
      break;
    }
    if(a[i] == a[i - 1]){
      ++slv[m];
    }
    else{
      slv[++m] = 1;
      fine[m] = lucky(a[i]);
    }
  }
  f[0][0] = 1;
  for(int i = 1; i <= m; ++i){
    for(int j = 0; j <= i; ++j){
      f[i][j] = f[i - 1][j];
      if(j > 0){
        f[i][j] += f[i - 1][j - 1] * slv[i];
      }
      f[i][j] %= mod;
    }
  }
  for(int i = 0; i <= min(m, k); ++i){
    answer += (1LL * f[m][i] * nCk(cnt, k - i));
    answer %= mod;
  }
  cout << answer;
  return 0;
}
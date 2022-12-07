#include <bits/stdc++.h>

using namespace std;

const int N = 1111;
const int mod = 1e9 + 7;

typedef pair < pair < int, int >, int > ii;

int n, m, k, tag;
int f[N][N];
int prefix[N][N];

void add(int &u, int v){
  u += v;
  if(u >= mod){
    u -= mod;
  }
}

void solve(int x){
  for(int i = 1; i <= max(m, n); ++i){
    prefix[i][x] = prefix[i - 1][x];
    add(prefix[i][x], f[i][x]);
  }
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  #endif // pts
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 1; i <= max(m, n); ++i){
    f[i][0] = 1;
    prefix[i][0] = 1;
  }
  for(int i = 1; i <= k; ++i){
    int sup = 0;
    for(int u = 3; u <= max(m, n); ++u){
      add(sup, prefix[u - 2][i - 1]);
      add(f[u][i], sup);
    }
    solve(i);
  }
  cout << (1LL * prefix[m][k] * prefix[n][k]) % mod;
  return 0;
}
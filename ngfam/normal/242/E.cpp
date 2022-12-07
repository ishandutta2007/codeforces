#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m;
int a[N];
int it[N * 4][30];
int lazy[N * 4];
int curr[30];

void recalc(int i){
  for(int u = 0; u < 20; ++u){
    it[i][u] = it[i * 2][u] + it[i * 2 + 1][u];
  }
}

void build(int i, int l, int r){
  if(l == r){
    for(int u = 0; u < 20; ++u){
      it[i][u] = ((a[l] >> u) & 1);
    }
    return;
  }
  int mid = (l + r) >> 1;
  build(i * 2, l, mid);
  build(i * 2 + 1, mid + 1, r);
  recalc(i);
}

void solve(int i, int len){
  if(lazy[i] != 0){
    int value = lazy[i];
    for(int u = 0; u < 20; ++u){
      if((value >> u) & 1){
        it[i][u] = len - it[i][u];
      }
    }
    lazy[i * 2] ^= value;
    lazy[i * 2 + 1] ^= value;
  }
  lazy[i] = 0;
}

void upd(int i, int l, int r, int d, int c, int val){
  solve(i, r - l + 1);
  if(l > c || d > r){
    return;
  }
  if(l >= d && r <= c){
    lazy[i] = val;
    solve(i, r - l + 1);
    return;
  }
  int mid = (l + r) >> 1;
  upd(i * 2, l, mid, d, c, val);
  upd(i * 2 + 1, mid + 1, r, d, c, val);
  recalc(i);
}

void query(int i, int l, int r, int d, int c){
  solve(i, r - l + 1);
  if(l > c || d > r){
    return;
  }
  if(l >= d && r <= c){
    for(int u = 0; u < 20; ++u){
      curr[u] += it[i][u];
    }
    return;
  }
  int mid = (l + r) >> 1;
  query(i * 2, l, mid, d, c);
  query(i * 2 + 1, mid + 1, r, d, c);
}

int main(){
  #ifdef pts
    freopen("1.inp", "r", stdin);
  //  freopen("1.out", "w", stdout);
  #endif
  scanf("%d", &n);
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  build(1, 1, n);
  scanf("%d", &m);
  for(int i = 1; i <= m; ++i){
    int type;
    scanf("%d", &type);
    if(type == 1){
      int l, r;
      scanf("%d%d", &l, &r);
      memset(curr, 0, sizeof curr);
      query(1, 1, n, l, r);
      long long answer = 0;
      for(int u = 0; u < 20; ++u){
        answer += 1LL * curr[u] * (1LL << u);
      }
      printf("%lld\n", answer);
    }
    else{
      int l, r, x;
      scanf("%d%d%d", &l, &r, &x);
      upd(1, 1, n, l, r, x);
    }
  }
  return 0;
}
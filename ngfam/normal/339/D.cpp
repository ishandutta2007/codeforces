#include <bits/stdc++.h>
#define mid ((l + r) >> 1)

using namespace std;

const int N = 1 << 20;

int n, m;
int a[N];
int it[N];
int lgr[N];

void build(int i, int l, int r){
  if(l == r){
    it[i] = a[l];
    return;
  }
  int opp = lgr[r - l + 1];
  build(i << 1, l, mid);
  build(i << 1 | 1, mid + 1, r);
  if(opp % 2 == 1){
    it[i] = it[i << 1] | it[i << 1 | 1];
  }
  else{
    it[i] = it[i << 1] ^ it[i << 1 | 1];
  }
}

void upd(int u, int l, int r, int pos, int val){
  if(l > pos || pos > r){
    return;
  }
  if(l == r){
    it[u] = val;
    return;
  }
  upd(u << 1, l, mid, pos, val);
  upd(u << 1 | 1, mid + 1, r, pos, val);
  int opp = lgr[r - l + 1];
  if(opp % 2 == 1){
    it[u] = it[u << 1] | it[u << 1 | 1];
  }
  else{
    it[u] = it[u << 1] ^ it[u << 1 | 1];
  }
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("1.inp", "r", stdin);
    //freopen(".out", "w", stdout);
  #endif // ONLINE_JUDGE
  scanf("%d%d", &n, &m);
  n = 1 << n;
  for(int i = 1; i <= n; ++i){
    scanf("%d", a + i);
  }
  for(int i = 1; i <= 20; ++i){
    lgr[1 << i] = i;
  }
  build(1, 1, n);
  for(int i = 1; i <= m; ++i){
    int u, v;
    scanf("%d%d", &u, &v);
    upd(1, 1, n, u, v);
    printf("%d\n", it[1]);
  }
  return 0;
}
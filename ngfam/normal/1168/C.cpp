#include <bits/stdc++.h>

using namespace std;

const int N = 300030;

int n, q;
int a[N];
int T[N << 2][19];

#define mid ((l + r) >> 1)

void build(int x, int l, int r) {
  if(l == r) {
    for(int i = 0; i < 19; ++i) if(a[r] & (1 << i)) T[x][i] = a[r];
    return;
  }


  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);

  int u = x + x, v = x + x + 1;
  for(int i = 0; i < 19; ++i) {
    //int new_val = T[x][i];
    T[x][i] = T[u][i] | T[v][i];
    for(int j = 0; j < 19; ++j) {
      if(T[u][i] & (1 << j)) T[x][i] |= T[v][j];
    }
  }
    //T[x][i] |= new_val

 
}

int cur;

void query(int x, int l, int r, int u, int v) {
  if(u > v) return;

  if(l > v || r < u) return;
  if(l >= u && r <= v) {
    int new_cur = cur;
    for(int i = 0; i < 19; ++i) {
      if(cur & (1 << i)) new_cur |= T[x][i];
    }
    cur |= new_cur;
    return;
  }

  query(x + x, l, mid, u, v);
  query(x + x + 1, mid + 1, r, u, v);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> q;
  for(int i = 1; i <= n; ++i) cin >> a[i];

  build(1, 1, n);

  while(q--) {
    int l, r;
    cin >> l >> r;

    cur = a[l];
    query(1, 1, n, l + 1, r - 1);


    if(cur & a[r]) cout << "Shi\n";
    else cout << "Fou\n";
  }


  return 0;
}
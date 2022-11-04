#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e6 + 123;
const int L = 21;

int h[N];
int up[N][L];

void calc_up(int v) {
  for (int i = 1; i < L; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
  }
}

int go_up(int v, int s) {
  for (int i = 0; i < L; i++) {
    if (s & (1 << i)) {
      v = up[v][i];
    }
  }
  
  return v;
}

int lca(int u, int v) {
  if (h[u] < h[v]) {
    swap(u, v);
  }
  
  u = go_up(u, h[u] - h[v]);
  
  if (u == v) {
    return u;
  }
  
  for (int i = L - 1; i >= 0; i--) {
    int uu = up[u][i];
    int vv = up[v][i];
    
    if (uu != vv) {
      u = uu;
      v = vv;
    }
  }
  
  return up[u][0];
}

int calc_dist(int u, int v) {
  int w = lca(u, v);
  return h[u] + h[v] - 2 * h[w];
}

int a, b;
int cur_d;
int cur;

void init() {
  a = 1;
  b = 2;
  cur_d = 2;
  cur = 4;
  
  for (int i = 1; i < 4; i++) {
    h[i] = 1;
    up[i][0] = 0;
  }
}

int add(int v) {
  up[cur][0] = v;
  h[cur] = h[v] + 1;
  calc_up(cur);
  
  up[cur + 1][0] = v;
  h[cur + 1] = h[v] + 1;
  calc_up(cur + 1);
  
  if (calc_dist(cur, a) > cur_d) {
    cur_d++;
    b = cur;
  } else if (calc_dist(cur, b) > cur_d) {
    cur_d++;
    a = cur;
  }
  
  cur += 2;
  return cur_d;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  init();
  
  int q;
  scanf("%d", &q);
  
  for (int i = 0; i < q; i++) {
    int v;
    scanf("%d", &v);
    v--;
    printf("%d\n", add(v));
  }
  
  return 0;
}
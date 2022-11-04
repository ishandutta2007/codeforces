#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 1e5 + 123;
const int M = 1 << 20;
const int MOD = 1e9 + 7;

void cut(int &x) {
  if (x >= MOD) {
    x -= MOD;
  }
  
  if (x < 0) {
    x += MOD;
  }
}

int n;
int a[N];
int tree[2 * M];

void upd(int i, int tl, int tr, int ind, int val) {
  if (tl == tr - 1) {
    tree[i] = val;
    return;
  }
  
  int tm = (tl + tr) / 2;
  if (ind < tm) {
    upd(2 * i + 1, tl, tm, ind, val);
  } else {
    upd(2 * i + 2, tm, tr, ind, val);
  }
  
  tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  cut(tree[i]);
}

int get(int i, int tl, int tr, int l, int r) {
  if (tl >= r || tr <= l) {
    return 0;
  }
  
  if (l <= tl && tr <= r) {
    return tree[i];
  }
  
  int tm = (tl + tr) / 2;
  int res = get(2 * i + 1, tl, tm, l, r) + get(2 * i + 2, tm, tr, l, r);
  cut(res);
  return res;
}

int main() {
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
    
  for (int i = 0; i < n; i++) {
    int x = a[i];
    int v = (get(0, 0, M, 0, x + 1) * 1LL * x) % MOD + x;
    cut(v);
    upd(0, 0, M, x, v);
  }
  
  cout << get(0, 0, M, 0, M) << "\n";
  
  return 0;
}
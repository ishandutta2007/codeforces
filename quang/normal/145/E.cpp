#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;
char s[N];
int f[4][N * 4];
bool t[N * 4];

void build(int node, int l, int r) {
  if (l == r) {
    if (s[l] == '4') {
      f[0][node] = 1;
    } else {
      f[3][node] = 1;
    }
    f[2][node] = f[1][node] = 1;
    return;
  }
  int m = (l + r) >> 1;
  int nodel = node * 2;
  int noder = node * 2 + 1;
  build(nodel, l, m);
  build(noder, m + 1, r);
  f[0][node] = f[0][nodel] + f[0][noder];
  f[3][node] = f[3][nodel] + f[3][noder];
  f[1][node] = max(f[1][nodel] + f[3][noder], f[0][nodel] + f[1][noder]);
  f[2][node] = max(f[2][nodel] + f[0][noder], f[3][nodel] + f[2][noder]);
}

void turn(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    t[node] ^= 1;
    swap(f[0][node], f[3][node]);
    swap(f[1][node], f[2][node]);
    return;
  }
  int m = (l + r) >> 1;
  int nodel = node * 2;
  int noder = node * 2 + 1;
  if (t[node]) {
    t[nodel] ^= 1;
    t[noder] ^= 1;
    t[node] = 0;
    swap(f[0][nodel], f[3][nodel]);
    swap(f[1][nodel], f[2][nodel]);
    swap(f[0][noder], f[3][noder]);
    swap(f[1][noder], f[2][noder]);
  }
  turn(nodel, l, m, x, y);
  turn(noder, m + 1, r, x, y);
  f[0][node] = f[0][nodel] + f[0][noder];
  f[3][node] = f[3][nodel] + f[3][noder];
  f[1][node] = max(f[1][nodel] + f[3][noder], f[0][nodel] + f[1][noder]);
  f[2][node] = max(f[2][nodel] + f[0][noder], f[3][nodel] + f[2][noder]);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cin >> (s + 1);
  build(1, 1, n);
  for (int i = 1; i <= m; i++) {
    string x;
    cin >> x;
    if (x[0] == 'c') {
      printf("%d\n", f[1][1]);
    } else {
      int l, r;
      cin >> l >> r;
      turn(1, 1, n, l, r);
    }
  }
  return 0;
}
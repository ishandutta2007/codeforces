#include <bits/stdc++.h>

using namespace std;

const int N = 300010;
const double Pi = acos(-1);

int n, m;
int len[N];
double dx[N * 4], dy[N * 4];
int angle[N * 4];

void refresh(int node, int leaf, int id) {
  if (leaf) {
    dx[node] = len[id];
    dy[node] = 0;
  } else {
    dx[node] = dx[node + node] + dx[node + node + 1];
    dy[node] = dy[node + node] + dy[node + node + 1];
  }
  double ca = cos(angle[node] * Pi / 180.0);
  double sa = sin(angle[node] * Pi / 180.0);
  double newdx = ca * dx[node] - sa * dy[node];
  double newdy = sa * dx[node] + ca * dy[node];
  dx[node] = newdx;
  dy[node] = newdy;
}

void inittree(int node, int l, int r) {
  if (l == r) {
    refresh(node, 1, l);
    return;
  }
  int m = (l + r) >> 1;
  inittree(node + node, l, m);
  inittree(node + node + 1, m + 1, r);
  refresh(node, 0, l);
}

void update(int node, int l, int r, int id) {
  if (r < id || id < l) {
    return;
  }
  if (l == r) {
    refresh(node, 1, l);
    return;
  }
  int m = (l + r) >> 1;
  update(node + node, l, m, id);
  update(node + node + 1, m + 1, r, id);
  refresh(node, 0, l);
}

void Rotate(int node, int l, int r, int x, int y, int alpha) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    angle[node] += alpha;
    refresh(node, l == r, l);
    return;
  }
  int m = (l + r) >> 1;
  Rotate(node + node, l, m, x, y, alpha);
  Rotate(node + node + 1, m + 1, r, x, y, alpha);
  refresh(node, l == r, l);
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    len[i] = 1;
  }
  inittree(1, 1, n);
  while (m--) {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a == 1) {
      len[b] += c;
      update(1, 1, n, b);
    } else {
      Rotate(1, 1, n, b, n, 360 - c);
    }
    printf("%0.17f %0.17f\n", dx[1], dy[1]);
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int a[N];
long long sum[N * 4];
int pos[N * 4];

void add(int node, int l, int r, int id, int val) {
  if (id < l || id > r) {
    return;
  }
  if (l == r) {
    sum[node] = val;
    pos[node] = id;
  } else {
    int m = (l + r) >> 1;
    add(node * 2, l, m, id, val);
    add(node * 2 + 1, m + 1, r, id, val);
    sum[node] = sum[node * 2] + sum[node * 2 + 1];
    if (a[pos[node * 2]] > a[pos[node * 2 + 1]]) {
      pos[node] = pos[node * 2];
    } else {
      pos[node] = pos[node * 2 + 1];
    }
  }
}

int getpos(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return pos[node];
  }
  int m = (l + r) >> 1;
  int p1 = getpos(node * 2, l, m, x, y);
  int p2 = getpos(node * 2 + 1, m + 1, r, x, y);
  if (a[p1] > a[p2]) {
    return p1;
  }
  return p2;
}

long long get(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 0;
  }
  if (x <= l && r <= y) {
    return sum[node];
  }
  int m = (l + r) >> 1;
  long long p1 = get(node * 2, l, m, x, y);
  long long p2 = get(node * 2 + 1, m + 1, r, x, y);
  return p1 + p2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  a[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    add(1, 1, n, i, a[i]);
  }
  while (m--) {
    int type;
    cin >> type;
    if (type == 1) {
      int l, r;
      cin >> l >> r;
      cout << get(1, 1, n, l, r) << endl;
    }
    if (type == 2) {
      int l, r, x;
      cin >> l >> r >> x;
      while (1) {
        int p = getpos(1, 1, n, l, r);
        if (a[p] < x) {
          break;
        }
        a[p] %= x;
        add(1, 1, n, p, a[p]);
      }
    }
    if (type == 3) {
      int k, x;
      cin >> k >> x;
      a[k] = x;
      add(1, 1, n, k, x);
    }
  }
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n, len, h;
int b[N], a[N];
int t[N * 4], s[N * 4];

void update(int node, int l, int r, int x, int y, int val) {
  if (x > r || y < l) {
    return;
  }
  if (x <= l && r <= y) {
    t[node] += val;
    s[node] += val;
    return;
  }
  int m = (l + r) >> 1;
  update(node + node, l, m, x, y, val);
  update(node + node + 1, m + 1, r, x, y, val);
  t[node] = max(t[node * 2], t[node * 2 + 1]) + s[node];
}

int main() {
  scanf("%d %d %d", &n, &len, &h);
  for (int i = 1; i <= len; i++) {
    scanf("%d", b + i);
  }
  sort(b + 1, b + len + 1, greater<int>());
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    int l = 0, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) >> 1;
      if (u + b[m] >= h) {
        l = m;
      } else {
        r = m;
      }
    }
    a[i] = l;
  }
  for (int i = 0; i <= len; i++) {
    update(1, 0, len, i, i, -i);
  }
  for (int i = 1; i < len; i++) {
    update(1, 0, len, a[i], len, 1);
  }
  int res = 0;
  for (int i = len; i <= n; i++) {
    update(1, 0, len, a[i], len, 1);
    res += (t[1] == 0);
    update(1, 0, len, a[i - len + 1], len, -1);
  }
  cout << res << endl;
  return 0;
}
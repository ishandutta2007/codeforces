#include <bits/stdc++.h>

using namespace std;

const int N = 210010;

struct it {
  int t[N * 4];

  void modify(int node, int l, int r, int id, int val) {
    if (l > id || r < id) {
      return;
    }
    if (l == r) {
      t[node] = val;
      return;
    }
    int m = (l + r) >> 1;
    modify(node + node, l, m, id, val);
    modify(node + node + 1, m + 1, r, id, val);
    t[node] = max(t[node + node], t[node + node + 1]);
  }

  int get(int node, int l, int r, int x, int y) {
    if (l > y || r < x) {
      return 0;
    }
    if (x <= l && r <= y) {
      return t[node];
    }
    int m = (l + r) >> 1;
    int p1 = get(node + node, l, m, x, y);
    int p2 = get(node + node + 1, m + 1, r, x ,y);
    return max(p1, p2);
  }
} segx, segy;

int n, m;
int x[N], y[N];
priority_queue <int> posx;
int st[20], top;

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int op, X, Y;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d %d", &X, &Y);
      Y += 200100 - i;
      x[X] = Y;
      y[Y] = X;
      top = 1;
      st[0] = Y;
      for (int i = 1; i <= 10; i++) {
        if (y[Y - i]) {
          st[top++] = Y - i;
          segx.modify(1, 1, n, y[Y - i], 0);
        }
      }
      for (int i = 0; i < top; i++) {
        int u = st[i];
        int f = segx.get(1, 1, n, y[u] + 1, n) + 1;
        segx.modify(1, 1, n, y[u], f);
        segy.modify(1, 1, N - 1, u, f);
      }
      posx.push(-X);
    } else {
      int cnt;
      scanf("%d", &cnt);
      top = 0;
      for (int i = 1; i <= cnt; i++) {
        int u = -posx.top();
        posx.pop();
        segy.modify(1, 1, N - 1, x[u], 0);
        st[top++] = u;
      }
      y[x[st[top - 1]]] = 0;
      x[st[top - 1]] = 0;
      segx.modify(1, 1, n, st[top - 1], 0);
      top--;
      for (int i = top - 1; i >= 0; i--) {
        int u = st[i];
        posx.push(-u);
        int f = segy.get(1, 1, N - 1, x[u] + 1, N - 1) + 1;
        segy.modify(1, 1, N - 1, x[u], f);
        segx.modify(1, 1, n, u, f);
      }
    }
    printf("%d\n", segx.t[1]);
  }
  return 0;
}
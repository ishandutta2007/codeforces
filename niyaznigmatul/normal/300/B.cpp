#include <cstdio>
#include <algorithm>

int p[55], ans[55][5], cn[55], cc[55];

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) p[i] = i, cn[i] = 0, cc[i] = 1;
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    --x;
    --y;
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      cc[y] += cc[x];
    }
  }
  for (int i = 0; i < n; i++) {
    if (i != get(i)) continue;
    if (cc[i] > 3) {
      puts("-1");
      return 0;
    }
    bool ok = false;
    for (int j = 0; j < n; j++) {
      if (i == j || j != get(j)) continue;
      if (cc[j] + cc[i] == 3) {
        p[i] = j;
        cc[j] += cc[i];
        ok = true;
        break;
      }
    }    
    for (int j = 0; !ok && j < n; j++) {
      if (i == j || j != get(j)) continue;
      for (int k = 0; !ok && k < n; k++) {
        if (j == k || i == k || k != get(k)) continue;
        if (cc[i] + cc[j] + cc[k] == 3) {
          p[i] = j;
          cc[j] += cc[i];
          p[k] = j;
          cc[j] += cc[k];
          ok = true;
          break;
        }
      }
    }
    if (cc[get(i)] != 3) {
      puts("-1");
      return 0;
    }
  }
  for (int i = 0; i < n; i++) {
    int x = get(i);
    ans[x][cn[x]++] = i;
  }
  for (int i = 0; i < n; i++) {
    if (cn[i] > 0) {
      printf("%d %d %d\n", ans[i][0] + 1, ans[i][1] + 1, ans[i][2] + 1);
    }
  }
}
#include <cstdio>

int const N = 12345;

int ax[N], ay[N], bx[N], by[N], p[N], was[N];

int get(int x) {
  return x == p[x] ? x : (p[x] = get(p[x]));
}

int main() {
  int n;
  scanf("%d", &n);
  int cn = 0;
  for (int i = 0; i < n; i++) p[i] = i;
  for (int i = 0; i + 1 < n; i++) {
    int v, u;
    scanf("%d%d", &v, &u);
    --v;
    --u;
    if (get(v) == get(u)) {
      ax[cn] = v;
      ay[cn] = u;
      ++cn;
    } else {
      p[get(v)] = get(u);
    }
  }  
  was[get(0)] = true;
  cn = 0;
  for (int i = 0; i < n; i++) {
    int f = get(i);
    if (was[f]) continue;
    was[f] = true;
    bx[cn] = 0;
    by[cn] = i;
    ++cn;
  }
  printf("%d\n", cn);
  for (int i = 0; i < cn; i++) {
    printf("%d %d %d %d\n", ax[i] + 1, ay[i] + 1, bx[i] + 1, by[i] + 1);
  }
}
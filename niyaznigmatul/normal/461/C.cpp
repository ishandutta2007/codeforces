#include <cstdio>

int const N = 223456;

int f[N];
int a[N];

void add(int x, int y) {
  for (int i = x; i < N; i |= i + 1) f[i] += y;
}

int get(int x) {
  int ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
    ret += f[i];
  }
  return ret;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  bool rev = false;
  for (int i = 0; i < n; i++) a[i] = 1;
  for (int i = 0; i < n; i++) add(i, 1);
  int cn = n;
  int sh = 0;
  for (int i = 0; i < q; i++) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      scanf("%d", &x);
      bool nrev = rev;
      if (2 * x > cn) nrev = !nrev;
      if (rev) x = cn - x;
      if (2 * x > cn) {
        x = cn - x;
        for (int i = 0; i < x; i++) {
          a[sh + cn - 2 * x + i] += a[sh + cn - i - 1];
          add(sh + cn - 2 * x + i, a[sh + cn - i - 1]);
        }
      } else {
        for (int i = 0; i < x; i++) {
          a[sh + 2 * x - i - 1] += a[sh + i];
          add(sh + 2 * x - i - 1, a[sh + i]);
//          printf("from %d to %d\n", sh + i, sh + 2 * x - i - 1);
        }
        sh += x;
      }
      cn -= x;
      rev = nrev;
    } else {
      int l, r;
      scanf("%d%d", &l, &r);
      if (rev) {
        int nl = cn - r;
        int nr = cn - l;
        l = nl;
        r = nr;
      }
      l += sh;
      r += sh;
//      printf("l, r = %d, %d, %d, %d\n", l, r, get(r - 1), get(l - 1));
      printf("%d\n", get(r - 1) - get(l - 1));
    }
//    for (int i = 0; i < cn; i++) printf("%d ", a[i + sh]);
//    puts("");
//    for (int i = 0; i < cn; i++) printf("%d ", get(i + sh) - get(i + sh - 1));
//    puts("");
//    printf("cn = %d\n", cn);
  }
}
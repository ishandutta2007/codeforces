#include <cstdio>

int w, n, m;
int cnt[1 << 12], a[1 << 12];
char gate[15];

void fwht(int n, int a[]) {
  for (int dim = 0; dim < w; ++dim) {
    int len = 1 << dim;
    for (int i = 0; i < n; i += len << 1) {
      for (int j = i; j < i + len; ++j) {
        int u = a[j], v = a[j + len];
        if (gate[dim] == 'X' || gate[dim] == 'x') {
          a[j] = u + v; a[j + len] = u - v;
        } else if (gate[dim] == 'A' || gate[dim] == 'a') {
          a[j] += v;
        } else {
          a[j + len] += u;
        }
      }
    }
  }
}

void ifwht(int n, int a[]) {
  for (int dim = 0; dim < w; ++dim) {
    int len = 1 << dim;
    for (int i = 0; i < n; i += len << 1) {
      for (int j = i; j < i + len; ++j) {
        int u = a[j], v = a[j + len];
        if (gate[dim] == 'X' || gate[dim] == 'x') {
          a[j] = u + v >> 1; a[j + len] = u - v >> 1;
        } else if (gate[dim] == 'A' || gate[dim] == 'a') {
          a[j] -= v;
        } else {
          a[j + len] -= u;
        }

        if (gate[dim] == 'x' || gate[dim] == 'a' || gate[dim] == 'o') {
          int t = a[j]; a[j] = a[j + len]; a[j + len] = t;
        }
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &w, &n, &m);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    ++cnt[a];
  }

  int len = 1 << w;
  for (int i = 0; i < m; ++i) {
    scanf("%s", gate);
    for (int l = 0, r = w-1; l < r; ++l, --r) {
      char t = gate[l]; gate[l] = gate[r]; gate[r] = t;
    }

    for (int j = 0; j < len; ++j) a[j] = cnt[j];
    fwht(len, a);
    for (int j = 0; j < len; ++j) a[j] *= a[j];
    ifwht(len, a);

    printf("%d\n", a[0]);
  }
  return 0;
}
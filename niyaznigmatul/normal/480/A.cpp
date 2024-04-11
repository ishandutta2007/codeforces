#include <cstdio>
#include <algorithm>

int const N = 12345;

int a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", a + i, b + i);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) if (a[i] > a[j] || (a[i] == a[j] && b[i] > b[j])) {
      std::swap(a[i], a[j]);
      std::swap(b[i], b[j]);
    }
  }
  int last = -(1 << 30);
  for (int i = 0; i < n; i++) {
    if (b[i] >= last) {
      last = b[i];
    } else last = a[i];
  }
  printf("%d\n", last);
}
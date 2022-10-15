#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &(a[i]));
  }
  vector<int> b(n);
  int c = getchar();
  while (c <= 32) c = getchar();
  for (int i = 0; i < n; i++) {
    b[i] = c - '0';
    c = getchar();
  }
  int s = 0;
  for (int i = 0; i < n; i++) s += a[i];
  int s2 = 0;
  int ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    s -= a[i];
    if (b[i] == 0) continue;
    if (b[i] == 1) {
      if (s + s2 > ans) ans = s + s2;
    }
    s2 += a[i];
  }
  if (s + s2 > ans) ans = s + s2;
  printf("%d\n", ans);
}
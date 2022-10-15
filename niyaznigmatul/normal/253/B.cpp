#include <cstdio>

int cn[5555];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    cn[x]++;
  }
  int s = 0;
  int ans = 1 << 30;
  for (int i = 0; i <= 2500; i++) {
    int s2 = 0;
    for (int j = 2 * i + 1; j <= 5000; j++) {
      s2 += cn[j];
    }
    if (s + s2 < ans) {
      ans = s + s2;
    }
    s += cn[i];
  }
  printf("%d\n", ans);
}
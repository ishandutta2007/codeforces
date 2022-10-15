#include <cstdio>

int a[777777], he[777777], ne[777777], ax[777777],  ay[777777];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n + n; i++) scanf("%d", a + i);
  for (int i = 0; i < 5555; i++) he[i] = -1;
  for (int i = 0; i < n + n; i++) {
    ne[i] = he[a[i]];
    he[a[i]] = i;
  }
  int ac = 0;
  for (int i = 0; i < 5555; i++) {
    int cnt = 0;
    for (int e = he[i]; e >= 0; e = ne[e]) {
      ++cnt;
    }
    if ((cnt & 1) == 1) {
      puts("-1");
      return 0;
    }
    for (int e = he[i]; e >= 0; e = ne[ne[e]]) {
      ax[ac] = e;
      ay[ac] = ne[e];
      ++ac;
    }
  }
//  printf("%d\n", ac);
  for (int i = 0; i < ac; i++) {
    printf("%d %d\n", ax[i] + 1, ay[i] + 1);
  }
}
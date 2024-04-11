#include <cstdio>


const int N = 123456;
int cn[N], he[N], ne[N], a[N], b[N], d[N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", d + i);
    cn[d[i]]++;
  }
  if (cn[0] != 1) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    long long can = (long long) (i == 1 ? k : (k - 1)) * cn[i - 1];
    if (cn[i] > can) {
      puts("-1");
      return 0;
    }    
  }
  for (int i = 0; i < n; i++) he[i] = -1;
  for (int i = 0; i < n; i++) {
    ne[i] = he[d[i]];
    he[d[i]] = i;
  }
  printf("%d\n", n - 1);
  for (int i = 0; i + 1 < n; i++) {
    int cn1 = 0;
    int cn2 = 0;
    for (int e = he[i]; e >= 0; e = ne[e]) a[cn1++] = e;
    for (int e = he[i + 1]; e >= 0; e = ne[e]) b[cn2++] = e;
    int can = i == 0 ? k : k - 1;
    int cur = 0;
    for (int j = 0; cur < cn2 && j < cn1; j++) {
      for (int t = 0; cur < cn2 && t < can; t++) {
        printf("%d %d\n", a[j] + 1, b[cur++] + 1);
      }
    }
  }
}
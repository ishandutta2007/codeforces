#include <cstdio>

int x[5555], y[5555], b[5555], ansx[5555], ansy[5555], c[5555];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", c + i);
  }
  int cn = 0;  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < c[i]; j++) {
      x[cn] = i + 1;
      y[cn] = j + 1;
      scanf("%d", b + cn);
      ++cn;
    }
  }
  int ansc = 0;
  for (int i = 0; i < cn; i++) {
    int best = i;
    for (int j = i + 1; j < cn; j++) {
      if (b[best] > b[j]) best = j;
    } 
    if (best != i) {
      ansx[ansc] = i;
      ansy[ansc] = best;
      ++ansc;
      int t = b[i];
      b[i] = b[best];
      b[best] = t;
    }
  }
  printf("%d\n", ansc);
  for (int i = 0; i < ansc; i++) {
    printf("%d %d %d %d\n", x[ansx[i]], y[ansx[i]], x[ansy[i]], y[ansy[i]]);
  }
}
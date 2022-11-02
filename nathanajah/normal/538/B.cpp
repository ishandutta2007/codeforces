#include <bits/stdc++.h>
using namespace std;

int tenpow[10];
char n[10];
int m;
int main() {
  tenpow[0] = 1;
  for (int i = 1; i < 10; i++) {
    tenpow[i] = tenpow[i-1] * 10;
  }
  scanf("%s",n);
  m = strlen(n);
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    maxi = max(maxi, n[i] - '0');
  }
  printf("%d\n", maxi);
  for (int i = 0; i < maxi; i++) {
    int now = 0;
    for (int j = 0; j < m; j++) {
      if (n[j] > '0') {
        --n[j];
        now += tenpow[m - 1 - j];
      }
    }
    printf("%d ", now);
  }
  printf("\n");
}
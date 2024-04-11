#include <cstdio>


int main() {
  int n;
  int a = 0;
  int b = 0;
  scanf("%d", &n);
  bool has = false;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    a += x;
    b += y;
    if ((x + y) & 1) has = true;
  }
  if ((a + b) & 1) {
    puts("-1");
  } else if ((a & 1) == 0 && (b & 1) == 0) 
    puts("0"); else if (has) {
      puts("1");
    } else {
      puts("-1");
    }
}
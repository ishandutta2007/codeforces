#include <stdio.h>
int n,i;
int main() {
  scanf("%d",&n);
  if (n<4) { puts("NO"); return 0; }
  puts("YES");
  for (i=n; i>5; i-=2) printf("%d - %d = 1\n1 * 1 = 1\n",i,i-1);
  if (i==4) {
    puts("3 + 1 = 4");
    puts("4 + 2 = 6");
    puts("6 * 4 = 24");
  } else {
    puts("5 * 4 = 20");
    puts("20 + 3 = 23");
    puts("23 + 2 = 25");
    puts("25 - 1 = 24");
  }
  return 0;
}
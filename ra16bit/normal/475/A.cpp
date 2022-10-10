#include <stdio.h>
int n,i,j,a[12];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    if (a[0]<4) a[0]++; else
      for (j=1; j<11; j++) if (a[j]<3) { a[j]++; break; }
  }
  puts("+------------------------+");
  putchar('|');
  for (i=0; i<11; i++) {
    putchar(a[i]>0?'O':'#');
    putchar('.');
  }
  puts("|D|)");
  putchar('|');
  for (i=0; i<11; i++) {
    putchar(a[i]>1?'O':'#');
    putchar('.');
  }
  puts("|.|");
  putchar('|');
  putchar(a[0]>2?'O':'#');
  puts(".......................|");
  putchar('|');
  putchar(a[0]>3?'O':'#');
  putchar('.');
  for (i=1; i<11; i++) {
    putchar(a[i]>2?'O':'#');
    putchar('.');
  }
  puts("|.|)");
  puts("+------------------------+");
  return 0;
}
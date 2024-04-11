#include <stdio.h>
int n,i;
char c;
int main() {
  scanf("%d\n",&n);
  for (i=0; i<n; i++) {
    c=getchar();
    putchar(c);
    if ((i&1) && i+1!=n && i+2!=n) putchar('-');
  }
  return 0;
}
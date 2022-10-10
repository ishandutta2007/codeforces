#include <stdio.h>
int i,j,n,r=-1,r1;
int main() {
  scanf("%d",&n);
  for (i=0; 4*i<=n; i++) if ((n-4*i)%7==0) {
    j=(n-4*i)/7;
    if (r==-1 || i+j<=r) { r=i+j; r1=i; }
  }
  if (r==-1) { printf("%d\n",r); return 0; }
  for (i=0; i<r1; i++) putchar('4');
  for (i=0; i<r-r1; i++) putchar('7');
  return 0;
}
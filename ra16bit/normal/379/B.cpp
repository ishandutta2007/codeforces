#include <stdio.h>
int n,i,a[321];
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (i=0; i<n; i++) {
    while (a[i]>0) {
      putchar('P');
      if (--a[i]==0) break;
      if (i>0) putchar('L');
      putchar('R');
      if (i==0) putchar('L');
    }
    if (i<n-1) putchar('R');
  }
  return 0;
}
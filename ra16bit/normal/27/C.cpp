#include <stdio.h>
int a1,a2,a,b1,b2,b,x,i,n,aa1,aa2,bb1,bb2;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&x);
    if (i) {
      if (a==1) {
        if (x<a1) { a1=x; aa1=i+1; } else if (x>a1) { a++; a2=x; aa2=i+1; }
      } else {
        if (x>a2) { a2=x; aa2=i+1; } else if (x<a2) { printf("3\n%d %d %d\n",aa1,aa2,i+1); return 0; }
      }
      if (b==1) {
        if (x>b1) { b1=x; bb1=i+1; } else if (x<b1) { b++; b2=x; bb2=i+1; }
      } else {
        if (x<b2) { b2=x; bb2=i+1; } else if (x>b2) { printf("3\n%d %d %d\n",bb1,bb2,i+1); return 0; }
      }
    } else a=b=aa1=bb1=1, a1=b1=x;
  }
  puts("0");
  return 0;
}
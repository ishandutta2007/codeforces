#include <stdio.h>
int n,i,l,r,h,a,b[1000100],c[1000100],res;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) { scanf("%d",&a); c[a]=i+1; }
  b[0]=100000000;
  for (i=0; i<n; i++) {
    scanf("%d",&a);
    a=c[a]; l=0; r=i+1;
    while (l<r) {
      h=(l+r)/2;
      if (b[h]>a) l=h+1; else r=h;
    }
    b[r]=a;
    if (r>res) res=r;
  }
  printf("%d\n",res);
  return 0;
}
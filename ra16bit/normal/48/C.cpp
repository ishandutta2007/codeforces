#include <stdio.h>
int n,i,j,a[1111];
double l,r,x;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  l=a[0]; r=a[0]+1;
  for (i=1; i<n; i++) {
    x=double(a[i])/(i+1.0);
    if (x>l) l=x;
    x=(a[i]+1.0)/(i+1.0);
    if (x<r) r=x;
  }
  i=int(l*(n+1)+1e-7);
  j=int((r-1e-7)*(n+1));
  if (i==j) {
    puts("unique");
    printf("%d\n",i);
  } else puts("not unique");
  return 0;
}
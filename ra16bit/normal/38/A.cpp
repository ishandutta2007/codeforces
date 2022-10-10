#include <stdio.h>
int n,x,y,i,r,a[111];
int main() {
  scanf("%d",&n);
  for (i=1; i<n; i++) scanf("%d",&a[i]);
  scanf("%d%d",&x,&y);
  for (i=x; i<y; i++) r+=a[i];
  printf("%d\n",r);
  return 0;
}
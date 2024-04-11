#include <stdio.h>
int n,m,k,r,i,x,y,a[1111];
int main() {
  scanf("%d%d%d",&n,&m,&k);
  for (i=1; i<=m; i++) a[i]=1000111000;
  for (i=0; i<n; i++) {
    scanf("%d%d",&x,&y);
    if (y<a[x]) a[x]=y;
  }
  for (i=1; i<=m; i++) r+=a[i];
  if (k<r) r=k;
  printf("%d\n",r);
  return 0;
}
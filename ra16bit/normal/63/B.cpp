#include <stdio.h>
int n,k,i,r,a[111];
int main() {
  scanf("%d%d",&n,&k); a[n]=k;
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  for (r=0; a[0]!=k; r++) for (i=0; i<n; i++) if (a[i]!=a[i+1]) a[i]++;
  printf("%d\n",r);
  return 0;
}
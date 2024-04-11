#include <stdio.h>
int n,m,i,a[55];
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  while (n>0 && a[n-1]==0) n--;
  if (m<=n) {
    while (a[m]==a[m-1]) m++;
  } else m=n;
  printf("%d\n",m);
  return 0;
}
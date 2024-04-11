#include <stdio.h>
int n,i,j,k,r,p[2020];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) scanf("%d",&p[i]);
  for (i=1; i<=n; i++) {
    for (j=i, k=0; j!=-1; j=p[j], k++);
    if (k>r) r=k;
  }
  printf("%d\n",r);
  return 0;
}
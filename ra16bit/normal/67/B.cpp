#include <stdio.h>
int i,j,e,n,k,a[1010],b[1010];
bool u[1010];
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&b[i]);
  for (i=0; i<n; i++) {
    for (j=0; j<n; j++) if (b[j]==0 && (!u[j])) break;
    for (e=0; e+k<=j; e++) if (!u[e]) b[e]--;
    a[i]=j+1; u[j]=true;
  }
  for (i=0; i<n; i++) {
    printf("%d",a[i]);
    if (i==n-1) putchar('\n'); else putchar(' ');
  }
  return 0;
}
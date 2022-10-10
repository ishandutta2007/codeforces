#include <stdio.h>
int n,m,x,i,j;
int main() {
  scanf("%d%d",&n,&m);
  if (n==1 && m==0) { puts("1"); return 0; }
  if (m<n/2 || n==1) { puts("-1"); return 0; }
  x=m-n/2+1;
  printf("%d %d",x,x*2);
  for (i=j=1; j<=n-2; i++) if (i!=x && i!=x*2) {
    printf(" %d",i);
    j++;
  }
  return 0;
}
#include <stdio.h>
int n,m,x,r,i,j;
int main() {
  scanf("%d%d%d",&n,&m,&x);
  for (i=x; i<=n-x+1; i++) for (j=x; j<=m-x+1; j++) if (((i+j)&1)==0 && (i==x || i==n-x+1 || j==x || j==m-x+1)) r++;
  printf("%d\n",r);
  return 0;
}
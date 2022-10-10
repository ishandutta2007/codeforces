#include <stdio.h>
int n,m,i,j;
int main() {
  scanf("%d%d",&n,&m);
  if (n*m>(n*(n-1))/2) { puts("-1"); return 0; }
  printf("%d\n",n*m);
  for (i=0; i<n; i++) for (j=1; j<=m; j++) printf("%d %d\n",i+1,(i+j)%n+1);
  return 0;
}
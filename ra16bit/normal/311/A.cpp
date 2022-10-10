#include <stdio.h>
int n,m,i;
int main() {
  scanf("%d%d",&n,&m);
  if (m>=(n*(n-1))/2) { puts("no solution"); return 0; }
  for (i=0; i<n; i++) printf("0 %d\n",i);
  return 0;
}
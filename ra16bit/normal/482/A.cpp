#include <stdio.h>
int n,m,i,c;
bool u[100100];
int main() {
  scanf("%d%d",&n,&m);
  for (c=i=1; i<m; i++) {
    printf("%d ",c);
    u[c]=true;
    if (c+n-i<=n && !u[c+n-i]) c+=n-i; else c-=n-i;
  }
  if (c+1<=n && !u[c+1]) for (; !u[c] && c<=n; c++) printf("%d ",c);
    else for (; !u[c] && c>=1; c--) printf("%d ",c);
  return 0;
}
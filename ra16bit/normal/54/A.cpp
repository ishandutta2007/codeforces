#include <stdio.h>
int n,k,m,i,x,z,r;
bool a[444];
int main() {
  scanf("%d%d%d",&n,&k,&m);
  for (i=0; i<m; i++) {
    scanf("%d",&x);
    a[x]=true;
  }
  for (i=1; i<=n; i++) if (a[i] || i-z==k) { r++; z=i; }
  printf("%d\n",r);
  return 0;
}
#include <stdio.h>
int n,m,i,j,r,x,num,a[1010],e[1010],w[1010];
int main() {
  scanf("%d%d",&n,&m);
  for (i=1; i<=n; i++) scanf("%d",&a[i]);
  for (i=0; i<m; i++) {
    scanf("%d",&x);
    e[w[x]]=0;
    for (j=w[x]+1; j<=num; j++) r+=e[j];
    w[x]=++num;
    e[num]=a[x];
  }
  printf("%d\n",r);
  return 0;
}
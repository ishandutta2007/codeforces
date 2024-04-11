#include <stdio.h>
int n,m,i,j,a[222],f[1000100],g[1000100];
void rec(int l, int x) {
  if (l==7) {
    a[m++]=x;
    return;
  }
  rec(l+1,x*10);
  rec(l+1,x*10+1);
}
int main() {
  scanf("%d",&n);
  rec(0,0);
  for (i=1; i<=n; i++) {
    f[i]=i; g[i]=1;
    for (j=1; a[j]<=i; j++) if (f[i-a[j]]+1<f[i]) {
      f[i]=f[i-a[j]]+1;
      g[i]=a[j];
    }
  }
  printf("%d\n",f[n]);
  for (i=0, j=n; i<f[n]; i++) {
    printf("%d ",g[j]);
    j-=g[j];
  }
  return 0;
}
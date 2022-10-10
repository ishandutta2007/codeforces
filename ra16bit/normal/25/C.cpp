#include <stdio.h>
int n,ii,i,j,x,y,z,m,a[333][333];
long long r;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%d",&a[i][j]);
  scanf("%d",&m);
  for (ii=0; ii<m; ii++) {
    scanf("%d%d%d",&x,&y,&z);
    x--; y--; r=0;
    for (i=0; i<n; i++) for (j=0; j<i; j++) {
      if (a[i][x]+z+a[y][j]<a[i][j]) a[i][j]=a[j][i]=a[i][x]+z+a[y][j];
      if (a[i][y]+z+a[x][j]<a[i][j]) a[i][j]=a[j][i]=a[i][y]+z+a[x][j];
      r+=a[i][j];
    }
    if (ii>0) putchar(' ');
    printf("%I64d",r);
  }
  return 0;
}
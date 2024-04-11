#include <stdio.h>
int n,i,j,k;
double a[20][20],f[1000000],p;
int main() {
  scanf("%d",&n); f[0]=1;
  for (i=0; i<n; i++) for (j=0; j<n; j++) scanf("%lf",&a[i][j]);
  for (i=0; i<(1<<n); i++) if (f[i]>0) {
    for (p=j=0; j<n; j++) if ((i&(1<<j))==0) p++;
    p=2.0/(p*(p-1));
    for (j=0; j<n; j++) if ((i&(1<<j))==0) for (k=j+1; k<n; k++) if ((i&(1<<k))==0) {
      f[i+(1<<j)]+=f[i]*a[k][j]*p;
      f[i+(1<<k)]+=f[i]*a[j][k]*p;
    }
  }
  for (i=0; i<n; i++) {
    if (i) putchar(' ');
    printf("%.8lf",f[(1<<n)-1-(1<<i)]);
  }
  return 0;
}
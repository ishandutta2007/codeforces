#include <stdio.h>
int n,m,h,i,j,k,a[1002],s[1002];
double c,d,f[1002][102][102];
int main() {
  scanf("%d%d%d",&n,&m,&h);
  for (i=1; i<=m; i++) scanf("%d",&a[i]);
  n--; a[h]--; f[0][0][0]=1.0;
  for (i=1; i<=m; i++) s[i]=s[i-1]+a[i];
  if (s[m]<n) { puts("-1.0"); return 0; }
  for (i=1; i<=m; i++) {
    for (k=0; k<=n; k++) f[i][0][k]=f[i-1][a[i-1]][k];
    for (j=0; j<=a[i]; j++) for (k=0; k<=n; k++) if (f[i][j][k]>0) {
      c=s[m]-s[i]+a[i]-j;
      d=double(n-k)/c;
      f[i][j+1][k]+=f[i][j][k]*(1.0-d);
      if (i!=h && k<n) f[i][j+1][k+1]+=f[i][j][k]*d;
    }
  }
  printf("%.8lf\n",1.0-f[m][a[m]][n]);
  return 0;
}
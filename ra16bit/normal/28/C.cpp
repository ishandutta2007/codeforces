#include <stdio.h>
int n,m,i,j,k,c,p,a[55];
long double f[55][55][55],q[55][55][55],mi,mq,r;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<m; i++) scanf("%d",&a[i]);
  for (i=1; i<=m; i++) {
    q[i][0][0]=1; mi=1.0; mq=i; mi=mi/mq;
    for (j=0; j<n; j++) for (k=0; k<=j; k++) if (q[i][j][k]>0) {
      q[i][j+1][k+1]+=q[i][j][k]*mi;
      q[i][j+1][k]+=q[i][j][k]*(1-mi);
    }
  }
  f[0][0][0]=1;
  for (i=0; i<m; i++) for (j=0; j<=n; j++) for (p=0; p<=j; p++) if (f[i][j][p]>0)
    for (c=k=0; j+k<=n; k++) {
      if (k>c*a[i]) c++;
      f[i+1][j+k][(c>p)?c:p]+=f[i][j][p]*q[m-i][n-j][k];
    }
  for (i=0; i<=n; i++) r+=f[m][n][i]*i;
  printf("%.12lf\n",double(r));
  return 0;
}
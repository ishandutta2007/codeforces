#include <stdio.h>
const int MX=505;
int n,m,i,j,it,i1,ii,l,a[MX][MX],sum[MX][MX],s[MX][MX],v[MX][MX],f[2][MX][MX],res=-1000000000;
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) for (j=0; j<m; j++) {
    scanf("%d",&a[i][j]);
    sum[i][j]=s[i][j]=v[i][j]=a[i][j];
    if (i>0) {
      sum[i][j]+=sum[i-1][j];
      v[i][j]+=v[i-1][j];
    }
    if (j>0) {
      sum[i][j]+=sum[i][j-1];
      s[i][j]+=s[i][j-1];
      if (i>0) sum[i][j]-=sum[i-1][j-1];
    }
  }
  for (i=0; i+2<n; i++) for (j=0; j+2<m; j++) {
    f[0][i][j]=a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2]+a[i+2][j]+a[i+2][j+1]+a[i+2][j+2];
    if (f[0][i][j]>res) res=f[0][i][j];
  }
  for (it=1; ; it++) {
    l=2*it+2; ii=(it&1); i1=1-ii;
    if (l>=n || l>=m) break;
    for (i=0; i+l<n; i++) for (j=0; j+l<m; j++) {
      f[ii][i][j]=sum[i+l-1][j+l-1]-sum[i+l-1][j]-sum[i][j+l-1]+sum[i][j]-f[i1][i+1][j+1];
      f[ii][i][j]+=s[i][j+l]-(j>0?s[i][j-1]:0);
      f[ii][i][j]+=s[i+l][j+l]-(j>0?s[i+l][j-1]:0);
      f[ii][i][j]+=v[i+l-1][j]-v[i+1][j];
      f[ii][i][j]+=v[i+l-1][j+l]-v[i][j+l];
      if (f[ii][i][j]>res) res=f[ii][i][j];
    }
  }
  printf("%d\n",res);
  return 0;
}
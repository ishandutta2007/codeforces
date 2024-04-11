#include <stdio.h>
const int MX=540;
int n,m,i,j,ii,i1;
double x,y,r,f[2][MX],s[MX];
int main() {
  for (i=1; i<MX; i++) s[i]=s[i-1]+i;
  for (i=1; i<MX; i++) s[i]/=i;
  scanf("%d%d",&n,&m);
  x=(m-1.)/m; y=1.-x;
  for (i=1; i<=n; i++) {
    ii=i&1; i1=1-ii;
    for (j=1; j<MX; j++) {
      f[ii][j]=f[i1][j]*x;
      f[ii][j]+=(f[i1][j]+s[j])*(j/(j+1.))*y;
      f[ii][j]+=(f[i1][j+1]+j)/(j+1.)*y;
    }
  }
  printf("%.11lf\n",f[n&1][1]*m);
  return 0;
}
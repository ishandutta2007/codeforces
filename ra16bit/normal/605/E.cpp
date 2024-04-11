#include <cstdio>
int n,i,j,k,a[1010][1010];
double cd,co,d[1010],o[1010],p[1010][1010];
bool was[1010];
int main() {
  scanf("%d",&n);
  for (i=1; i<=n; i++) for (j=1; j<=n; j++) {
    scanf("%d",&a[i][j]);
    p[i][j]=a[i][j]/100.;
  }
  for (i=1; i<n; i++) d[i]=1e20;
  while (true) {
    for (k=-1, i=1; i<=n; i++) if (!was[i] && (k==-1 || d[i]<d[k])) k=i;
    was[k]=true;
    if (k==1) break;
    for (i=1; i<=n; i++) if (!was[i] && a[i][k]>0) {
      if (d[i]>1e19) {
        o[i]=1-p[i][k];
        d[i]=(1+p[i][k]*d[k])/(1-o[i]);
      } else {
        cd=d[i]*(1-o[i])+o[i]*p[i][k]*d[k];
        co=o[i]*(1-p[i][k]);
        if (cd/(1-co)<d[i]) {
          d[i]=cd/(1-co);
          o[i]=co;
        }
      }
    }
  }
  printf("%.14lf\n",d[1]);
  return 0;
}
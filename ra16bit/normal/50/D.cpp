#include <stdio.h>
#include <math.h>
int n,k,X,Y,i,j,e,x[111],y[111],d[111];
double l,r,h,H,p,f[111][111],eps=1e-7;
int main() {
  scanf("%d%d%d%d%d",&n,&k,&e,&X,&Y);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    d[i]=(X-x[i])*(X-x[i])+(Y-y[i])*(Y-y[i]);
  }
  l=0; r=10000;
  while (l<r-eps) {
    h=(l+r)*0.5; H=h*h; f[0][0]=1.0;
    for (i=1; i<=n; i++) for (j=0; j<=i; j++) f[i][j]=0;
    for (i=0; i<n; i++) {
      if (d[i]>H) p=exp(1.0-double(d[i])/H); else p=1.0;
      for (j=0; j<=i; j++) {
        f[i+1][j+1]+=p*f[i][j];
        f[i+1][j]+=(1-p)*f[i][j];
      }
    }
    for (p=i=0; i<k; i++) p+=f[n][i];
    if (p*1000>e) l=h; else r=h;
  }
  printf("%.11lf\n",r);
  return 0;
}
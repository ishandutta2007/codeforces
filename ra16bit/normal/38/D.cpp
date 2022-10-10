#include <stdio.h>
int i,j,k,n,x1,y1,x2,y2,x[111],y[111],z[111];
double xx,yy,zz,t,eps=1e-8;
double abs(double x) { return (x<0)?(-x):x; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x[i]=(x1+x2);
    y[i]=(y1+y2);
    z[i]=(x2>x1)?x2-x1:x1-x2;
    for (j=0; j<i; j++) {
      xx=yy=zz=0;
      for (k=j+1; k<=i; k++) { t=z[k]*z[k]*z[k]; xx+=x[k]*t; yy+=y[k]*t; zz+=t; }
      xx/=zz; yy/=zz;
      if (abs(xx-x[j])>z[j]+eps || abs(yy-y[j])>z[j]+eps) { printf("%d\n",i); return 0; }
    }
  }
  printf("%d\n",n);
  return 0;
}
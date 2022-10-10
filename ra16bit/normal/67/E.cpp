#include <stdio.h>
int n,i,j,r,x[1010],y[1010];
long long a,b,c,A,B,C,q3,Y;
double x_,y_,e,x0,y0,x1,y1,q1,q2,eps=1e-8;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
  A=y[1]-y[0]; x0=x[0]; x1=x[1];
  B=x[0]-x[1]; y0=y[0]; y1=y[1];
  C=-A*x[0]-B*y[0];
  for (i=2; i<n-1; i++) {
    a=y[i+1]-y[i];
    b=x[i]-x[i+1];
    c=-a*x[i]-b*y[i];
    q1=a*x0+b*y0+c;
    q2=a*x1+b*y1+c;
    if (q1<-eps && q2<-eps) { puts("0"); return 0; }
    if (q1>-eps && q2>-eps) continue;
    if (A==0) {
      e=double(A)/double(a);
      y_=(-C+e*c)/(B-e*b);
      x_=(-c-b*y_)/double(a);
    } else {
      e=double(a)/double(A);
      y_=(-c+e*C)/(b-e*B);
      x_=(-C-B*y_)/double(A);
    }
    if (q1<-eps) { x0=x_; y0=y_; } else if (q2<-eps) { x1=x_; y1=y_; }
  }
  if (A==0) {
    if (x1<x0) { e=x0; x0=x1; x1=e; }
    i=int(x0-eps);
    if (i+eps<x0) i++;
    for (; i<x1+eps; i++) {
      Y=(long long)((-A*i-C)/double(B)+eps);
      if (A*i+B*Y+C==0) r++;
    }
  } else {
    if (y1<y0) { e=y0; y0=y1; y1=e; }
    i=int(y0-eps);
    if (i+eps<y0) i++;
    for (; i<y1+eps; i++) {
      Y=(long long)((-B*i-C)/double(A)+eps);
      if (A*Y+B*i+C==0) r++;
    }
  }
  printf("%d\n",r);
  return 0;
}
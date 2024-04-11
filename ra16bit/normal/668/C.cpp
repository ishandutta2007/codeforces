#include <stdio.h>
#include <math.h>
int n,i;
double x[100100],y[100100],a[100100],b[100100],B,C,D,p=1,q=1;
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%lf",&a[i]);
  for (i=0; i<n; i++) scanf("%lf",&b[i]);
  for (i=0; i<n; i++) {
    B=q-p-a[i]-b[i];
    C=(a[i]+b[i])*p-b[i];
    D=B*B-4*C;
    if (D<0) D=0;
    x[i]=0.5*(-B-sqrt(D));
    y[i]=a[i]+b[i]-x[i];
    p-=x[i];
    q-=y[i];
  }
  for (i=0; i<n; i++) printf("%.8lf ",x[i]); puts("");
  for (i=0; i<n; i++) printf("%.8lf ",y[i]); puts("");
  return 0;
}
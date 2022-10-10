#include <stdio.h>
int i,j,x[333],y[333];
double r,z;
double sqr(double x) { return x*x; }
int main() {
  x[0]=0; y[0]=1000000;
  for (i=301; i>=1; i--) {
    x[302-i]=500000-i*1000;
    y[302-i]=i;
  }
  x[302]=y[302]=1000000;
  puts("303");
  for (i=0; i<=302; i++) {
    r=y[i];
    for (j=i-1; j>=0; j--) {
      z=sqr(x[i]-x[j])/(4.0*y[j]);
      if (z<r) r=z;
    }
    //if (r<y[i]-0.5) printf("%d %.5lf\n",i,r);
    printf("%d %d\n",x[i],y[i]);
  }
  return 0;
}
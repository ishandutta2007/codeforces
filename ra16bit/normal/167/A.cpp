#include <stdio.h>
#include <math.h>
int n,a,d,t,v,i;
double tm,prev;
int main() {
  scanf("%d%d%d",&n,&a,&d);
  for (i=0; i<n; i++) {
    scanf("%d%d",&t,&v);
    tm=sqrt(2.0*d/double(a));
    if (a*tm>v) {
      tm=(1.0*v)/a;
      tm+=(d-a*tm*tm*0.5)/v;
    }
    tm+=t;
    if (tm<prev) tm=prev;
    printf("%.8lf\n",tm);
    prev=tm;
  }
  return 0;
}
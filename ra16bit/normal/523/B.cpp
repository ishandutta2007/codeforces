#include <stdio.h>
#include <math.h>
int n,m,q,i,x,a[200200];
double s,c,cur,mean;
int main() {
  scanf("%d%d%lf",&n,&m,&c);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  scanf("%d",&q);
  for (i=0; q--;) {
    scanf("%d",&x);
    for (; i<x; i++) {
      s+=a[i];
      if (i>=m) s-=a[i-m];
      mean=(mean+double(a[i])/m)/c;
    }
    cur=s/m;
    printf("%.10lf %.10lf %.10lf\n",cur,mean,fabs(mean-cur)/cur);
  }
}
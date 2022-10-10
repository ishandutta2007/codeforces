#include <stdio.h>
int n,k,i,a[10010];
double l,r,h,c,d;
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&a[i]);
  l=0; r=1010;
  while (l<r-1e-8) {
    h=(l+r)*0.5;
    for (c=d=i=0; i<n; i++) if (a[i]>h) { c+=a[i]-h; d+=h; } else d+=a[i];
    if (d+c*(100-k)*0.01>=h*n) l=h; else r=h;
  }
  printf("%.8lf\n",r);
  return 0;
}
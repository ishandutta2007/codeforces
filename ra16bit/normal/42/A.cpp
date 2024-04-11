#include <stdio.h>
int n,i,a[22],b,sa,v;
double c,r;
int main() {
  scanf("%d%d",&n,&v);
  for (i=0; i<n; i++) { scanf("%d",&a[i]); sa+=a[i]; }
  r=double(v)/double(sa);
  for (i=0; i<n; i++) {
    scanf("%d",&b);
    c=double(b)/double(a[i]);
    if (c<r) r=c;
  }
  printf("%.7lf\n",r*sa);
  return 0;
}
#include <stdio.h>
int a,b,y,z;
double x,r=-1;
int main() {
  scanf("%d%d",&a,&b);
  y=a-b;
  if (y==0) r=b; else if (y>=b) {
    z=y/b;
    if (z%2) z--;
    if (z>0) r=double(y)/z;
  }
  y=a+b;
  z=y/b;
  if (z%2) z--;
  if (z>0) {
    x=double(y)/z;
    if (r<0 || r>x) r=x;
  }
  if (r<0) puts("-1"); else printf("%.15lf\n",r);
  return 0;
}
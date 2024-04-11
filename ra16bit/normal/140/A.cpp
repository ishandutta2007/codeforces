#include <stdio.h>
#include <math.h>
int a,b,n;
double x;
int main() {
  scanf("%d%d%d",&n,&a,&b);
  if (n==1) puts((a>=b)?"YES":"NO"); else
    if (n==2) puts((a>=2*b)?"YES":"NO"); else if (a>=2*b) {
      x=asin(double(b)/double(a-b));
      puts((x*n<3.1415926536)?"YES":"NO");
    } else puts("NO");
  return 0;
}
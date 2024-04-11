#include <stdio.h>
#include <math.h>
int a,b,c;
long long bb,d;
double x,y,dd;
int main() {
  scanf("%d%d%d",&a,&b,&c);
  if (a==0) {
    if (b==0) {
      if (c==0) puts("-1"); else puts("0");
    } else {
      puts("1");
      printf("%.10lf\n",double(-c)/double(b));
    }
    return 0;
  }
  if (c==0) {
    if (a==0) {
      puts("1");
      puts("0");
    } else {
      if (b==0) {
        puts("1\n0.0000000000");
      } else {
        puts("2");
        x=double(-b)/double(a);
        if (x<0) printf("%.10lf\n0.0000000000\n",x); else printf("0.0000000000\n%.10lf\n",x);
      }
    }
    return 0;
  }
  bb=b;
  d=bb*bb-4LL*a*c;
  if (d==0) {
    puts("1");
    printf("%.10lf\n",double(-b)/double(2*a));
  } else if (d>0){
    puts("2");
    dd=sqrt(double(d));
    x=(-b-dd)/double(2*a);
    y=(-b+dd)/double(2*a);
    if (x<y) printf("%.10lf\n%.10lf\n",x,y); else printf("%.10lf\n%.10lf\n",y,x);
  } else puts("0");
  return 0;
}
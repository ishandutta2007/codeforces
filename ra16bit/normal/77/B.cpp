#include <cstdio>
using namespace std;
int t,a,b;
double r;
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&a,&b);
    if (a==0) {
      if (b==0) puts("1"); else puts("0.5");
    } else if (b>0) {
      if (a>4*b) r=(2.0*b)*(1.0*b)+(a-4.0*b)*(1.0*b); else r=(0.25*a)*(0.5*a);
      r/=(2.0*a)*double(b);
      printf("%.10lf\n",0.5+r);
    } else puts("1");
  }
  return 0;
}
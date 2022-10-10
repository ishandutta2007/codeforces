#include <bits/stdc++.h>
using namespace std;
const int MX=200200;
int t,n,i,x,y,an,bn,a[MX],b[MX];
double r;
double sqr(double x) { return x*x; }
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d",&n);
    for (an=bn=i=0; i<2*n; i++) {
      scanf("%d%d",&x,&y);
      if (x==0) {
        a[an++]=(y<0)?-y:y;
      } else if (y==0) {
        b[bn++]=(x<0)?-x:x;
      }
    }
    sort(a,a+an);
    sort(b,b+bn);
    for (r=i=0; i<an && i<bn; i++) r+=sqrt(sqr(a[i])+sqr(b[i]));
    printf("%.14lf\n",r);
  }
  return 0;
}
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
const double pi=acos(-1.);
int n,ra,v,x,y,e,it;
double l,r,h,d,len,a;
int main() {
  scanf("%d%d%d",&n,&ra,&v);
  len=2*pi*ra;
  while (n--) {
    scanf("%d%d",&x,&y);
    x=y-x;
    l=max(0.,ra-0.5*x);
    r=2*ra;
    for (it=0; it<100; it++) {
      h=(l+r)*0.5;
      d=x+2*(h-ra);
      e=int(d/len);
      d-=e*len;
      a=asin((ra-h)/ra)*2*ra;
      if (d>=a && d<=len-a) r=h; else l=h;
    }
    printf("%.15lf\n",(x-2*ra+(l+r))/v);
  }
  return 0;
}
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int IT=300;
int s,a,b,c;
long double l,r,h1,h2,s1,s2,eps=1e-12;
long double sol(long double x, long double y, bool w) {
  if (w) printf("%.14lf %.14lf %.14lf\n",double(x),double(y),max(0.0,double(s-x-y-eps)));
  long double res=0;
  //printf("==== %.5lf %.5lf\n",double(x),double(y));
  if (x>eps) res+=a*log(x);
  //printf("%.5lf\n",double(res));
  if (y>eps) res+=b*log(y);
  //printf("%.5lf\n",double(res));
  if (s-x-y>eps) res+=c*log(s-x-y);
  //printf("%.5lf\n",double(res));
  return res;
}
long double solve(long double x, bool w) {
  long double l=0,r=b?(s-x):0,h1,h2,s1,s2;
  for (int i=0; i<IT; i++) {
    h1=(2*l+r)/3;
    h2=(l+2*r)/3;
    s1=sol(x,h1,false);
    s2=sol(x,h2,false);
    if (s1>s2) r=h2; else l=h1;
  }
  return sol(x,(l+r)*0.5,w);
}
int main() {
  scanf("%d%d%d%d",&s,&a,&b,&c);
  l=0; r=a?s:0;
  for (int i=0; i<IT; i++) {
    h1=(2*l+r)/3;
    h2=(l+2*r)/3;
    s1=solve(h1,false);
    s2=solve(h2,false);
    //printf("%.2lf %.2lf | %.2lf %.2lf = %.2lf %.2lf\n",double(l),double(r),double(h1),double(h2),double(s1),double(s2));
    if (s1>s2) r=h2; else l=h1;
  }
  solve((h1+h2)*0.5,true);
  return 0;
}
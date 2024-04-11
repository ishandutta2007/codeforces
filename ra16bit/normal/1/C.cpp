#include <cstdio>
#include <cmath>
using namespace std;
double x[3],y[3],a1,b1,c1,a2,b2,c2,r,d,l,e,xx,yy;
int i,j,k,kk;
bool q;
int main() {
  for (i=0; i<3; i++) scanf("%lf%lf",&x[i],&y[i]);
  a1=x[0]-x[1]; b1=y[0]-y[1]; c1=-a1*(x[0]+x[1])/2.0-b1*(y[0]+y[1])/2.0;
  a2=x[1]-x[2]; b2=y[1]-y[2]; c2=-a2*(x[1]+x[2])/2.0-b2*(y[1]+y[2])/2.0;
  if (a1==0) {
    l=-b2/a2; e=-c2/a2;
    yy=(-a1*e-c1)/(a1*l+b1);
    xx=l*yy+e;
  } else {
    l=-b1/a1; e=-c1/a1;
    yy=(-a2*e-c2)/(a2*l+b2);
    xx=l*yy+e;
  }
  r=(xx-x[0])*(xx-x[0])+(yy-y[0])*(yy-y[0]);
  for (i=3; i<=1000; i++) {
    q=true;
    l=6.28318530718/i;
    for (j=0; j<3; j++) for (k=j+1; k<3; k++) {
      d=(x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]);
      e=acos(1-d/(2*r));
      while (e<0) e+=6.28318530718;
      e/=l; kk=int(e);
      if (fabs(e-kk)>1e-5 && fabs(e-kk+1)>1e-5 && fabs(e-kk-1)>1e-5) q=false;
    }
    if (q) {
      printf("%.6lf\n",i*0.5*r*sin(l));
      return 0;
    }
  }
      printf("%.6lf\n",3.1415926535*r);
      return 0;
}
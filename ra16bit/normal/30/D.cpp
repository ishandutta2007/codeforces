#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,i,x[111111],xx,yy,z;
double x1,x2,x_,y_,x0,c,r,xb;
int main() {
  scanf("%d%d",&n,&k);
  for (i=0; i<n; i++) scanf("%d",&x[i]);
  scanf("%d%d",&xx,&yy);
  if (k!=n+1) z=x[k-1]; else z=1000000000;
  sort(x,x+n);
  if (k==n+1) {
    x1=xx-x[0]; x2=xx-x[n-1]; y_=yy;
    x1*=x1; x2*=x2; y_*=y_;
    if (x1>x2) x1=x2;
    printf("%.10lf\n",x[n-1]-x[0]+sqrt(x1+y_));
    return 0;
  }
  if (z==x[0]) {
    x_=xx-x[n-1]; y_=yy;
    x_*=x_; y_*=yy;
    r=x[n-1]-x[0]+sqrt(x_+y_);
    for (i=1; i<n; i++) {
      x_=xx-x[i-1]; x1=xx-x[n-1]; x2=xx-x[i]; y_=yy;
      x1*=x1; x2*=x2; x_*=x_; y_*=y_;
      if (x1>x2) x1=x2;
      c=x[n-1]-x[0]-x[i]+x[i-1]+sqrt(x_+y_)+sqrt(x1+y_);
      if (c<r) r=c;
    }
    printf("%.10lf\n",r);
    return 0;
  }
  if (z==x[n-1]) {
    x_=xx-x[0]; y_=yy;
    x_*=x_; y_*=yy;
    r=x[n-1]-x[0]+sqrt(x_+y_);
    for (i=1; i<n; i++) {
      x_=xx-x[i]; x1=xx-x[0]; x2=xx-x[i-1]; y_=yy;
      x1*=x1; x2*=x2; x_*=x_; y_*=y_;
      if (x1>x2) x1=x2;
      c=x[n-1]-x[0]-x[i]+x[i-1]+sqrt(x_+y_)+sqrt(x1+y_);
      if (c<r) r=c;
    }
    printf("%.10lf\n",r);
    return 0;
  }
  for (i=0; i<n; i++) if (z==x[i]) { k=i; break; }
  x_=xx-x[n-1]; y_=yy;
  x_*=x_; y_*=yy;
  r=x[k]-x[0]+x[n-1]-x[0]+sqrt(x_+y_);
  x_=xx-x[0]; y_=yy;
  x_*=x_; y_*=yy;
  c=x[n-1]-x[k]+x[n-1]-x[0]+sqrt(x_+y_);
  if (c<r) r=c;
  xb=x[n-1]-x[0];
  for (i=1; i<=k; i++) {
    x_=xx-x[i-1]; x0=xx-x[0];
    x1=xx-x[i]; x2=xx-x[n-1]; y_=yy;
    x_*=x_; x0*=x0; x1*=x1; x2*=x2; y_*=y_;
    if (x1>x2) x1=x2;
    c=xb-x[i]+x[i-1]+min(x[n-1]-x[k]+sqrt(x1+y_),x[k]-x[i]+sqrt(x2+y_))+sqrt(min(x_,x0)+y_);
    if (c<r) r=c;
  }
  for (i=k+1; i<n; i++) {
    x_=xx-x[i]; x0=xx-x[n-1];
    x1=xx-x[i-1]; x2=xx-x[0]; y_=yy;
    x_*=x_; x0*=x0; x1*=x1; x2*=x2; y_*=y_;
    if (x1>x2) x1=x2;
    c=xb-x[i]+x[i-1]+min(x[k]-x[0]+sqrt(x1+y_),x[i-1]-x[k]+sqrt(x2+y_))+sqrt(min(x_,x0)+y_);
    if (c<r) r=c;
  }
  printf("%.10lf\n",r);
  return 0;
}
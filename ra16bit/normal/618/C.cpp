#include <cstdio>
#include <algorithm>
using namespace std;
int n,i,w,zw,x[100100],y[100100];
long long a,b,c,zcur,cur,r;
long long sqr(long long x) { return x*x; }
long long dist(int i, int j) {
  return sqr(x[i]-x[j])+sqr(y[i]-y[j]);
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) scanf("%d%d",&x[i],&y[i]);
  zcur=dist(0,1); zw=1;
  for (i=2; i<n; i++) {
    cur=dist(0,i);
    if (cur<zcur) { zcur=cur; zw=i; }
  }
  a=y[zw]-y[0];
  b=x[0]-x[zw];
  c=-a*x[0]-b*y[0];
  for (i=1; i<n; i++) if (i!=zw) {
    cur=abs(a*x[i]+b*y[i]+c);
    if (cur>0 && (w==0 || cur<r)) { r=cur; w=i; }
  }
  printf("1 %d %d\n",min(zw,w)+1,max(zw,w)+1);
  return 0;
}
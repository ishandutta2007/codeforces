#include <stdio.h>
int i,j,n,t,X,Y,x[222000],y[222000];
long long r,z;
long long cross(long long xa, long long ya, long long xb, long long yb) { return xa*yb-xb*ya; }
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d%d",&x[i],&y[i]);
    x[i+n]=x[i]; y[i+n]=y[i];
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&X,&Y);
    for (i=0; i<n; i++) if (cross(x[i+1]-x[i],y[i+1]-y[i],X-x[i+1],Y-y[i+1])>=0) break;
    if (i<n) { puts("0"); continue; }
    r=(n*(n-1LL)*(n-2LL))/6LL;
    for (i=0,j=1; i<n; i++) {
      while (cross(x[j+1]-x[i],y[j+1]-y[i],X-x[j+1],Y-y[j+1])<0) j++;
      r-=((j-i)*(j-i-1LL))/2LL;
    }
    printf("%I64d\n",r);
  }
  return 0;
}
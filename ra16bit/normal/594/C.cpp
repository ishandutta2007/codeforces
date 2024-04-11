#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=100100;
int n,m,ia,ib,ic,id,i,j,k,e,cnt,cur,xl,xr,yl,yr,a[MX],b[MX],c[MX],d[MX],u[MX];
long long x[MX],y[MX],pxa,pxb,pya,dx,r=4000000000000000000LL;
bool cmpxa(int i, int j) { return x[i]<x[j]; }
bool cmpxb(int i, int j) { return x[i]>x[j]; }
bool cmpya(int i, int j) { return y[i]<y[j]; }
bool cmpyb(int i, int j) { return y[i]>y[j]; }
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) {
    scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
    x[i]=xl+xr;
    y[i]=yl+yr;
    a[i]=b[i]=c[i]=d[i]=i;
  }
  sort(a,a+n,cmpxa);
  sort(b,b+n,cmpxb);
  sort(c,c+n,cmpya);
  sort(d,d+n,cmpyb);
  for (ia=0; cnt<=m; ia++) {
    i=a[ia];
    if (ia==0 || x[i]!=pxa) {
      for (ib=0; cnt<=m; ib++) {
        j=b[ib];
        if ((ib==0 || x[j]!=pxb) && x[i]<=x[j]) {
          dx=max((x[j]-x[i]+1)/2,1LL);
          for (ic=0; cnt<=m; ic++) {
            k=c[ic];
            if (ic==0 || y[k]!=pya) {
              for (cur=id=0; id<n; id++) {
                e=d[id];
                if (u[e]==0) cur++;
                if (cnt+cur>m) {
                  if (y[k]<=y[e]) r=min(r,dx*max((y[e]-y[k]+1)/2,1LL));
                  break;
                }
              }
            }
            if (u[k]==0) { u[k]=3; cnt++; }
            pya=y[k];
          }
          for (; ic>=0; ic--) {
            k=c[ic];
            if (u[k]==3) { u[k]=0; cnt--; }
          }
        }
        if (u[j]==0) { u[j]=2; cnt++; }
        pxb=x[j];
      }
      for (; ib>=0; ib--) {
        j=b[ib];
        if (u[j]==2) { u[j]=0; cnt--; }
      }
    }
    u[i]=1; cnt++;
    pxa=x[i];
  }
  printf("%I64d\n",r);
  return 0;
}
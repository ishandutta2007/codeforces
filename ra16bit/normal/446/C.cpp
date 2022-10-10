#include <cstdio>
#include <algorithm>
using namespace std;
const int md=1000000009,MX=321300,BS=460;
int n,m,i,r,t,x,y,bx,by,a[MX],f[MX],sf[MX],b[MX],s1[MX],s2[MX];
void modify(int x, int y, int bx, int st) {
  for (int i=x; i<y; i++) {
    a[i]=(a[i]+f[i-st])%md;
    b[bx]=(b[bx]+f[i-st])%md;
  }
}
int zcount(int x, int y, int bx) {
  if (s1[bx]+s2[bx]>0) {
    for (int i=bx*BS; i<(bx+1)*BS; i++) {
      a[i]=(a[i]+s1[bx])%md;
      s1[bx]=(s1[bx]+s2[bx])%md;
      swap(s1[bx],s2[bx]);
    }
    s1[bx]=s2[bx]=0;
  }
  int r=0;
  for (int i=x; i<y; i++) r=(r+a[i])%md;
  return r;
}
int main() {
  scanf("%d%d",&n,&m);
  f[1]=f[2]=1;
  for (i=3; i<=n; i++) f[i]=(f[i-1]+f[i-2])%md;
  for (i=1; i<=n; i++) {
    scanf("%d",&a[i]);
    b[i/BS]=(b[i/BS]+a[i])%md;
    sf[i]=(sf[i-1]+f[i])%md;
  }
  while (m--) {
    scanf("%d%d%d",&t,&x,&y);
    bx=x/BS; by=y/BS;
    if (t==1) {
      if (bx<by) {
        modify(x,(bx+1)*BS,bx,x-1);
        modify(by*BS,y+1,by,x-1);
        for (i=bx+1; i<by; i++) {
          s1[i]=(s1[i]+f[i*BS-x+1])%md;
          s2[i]=(s2[i]+f[i*BS-x+2])%md;
          b[i]=(b[i]+(sf[(i+1)*BS-x]+md-sf[i*BS-x])%md)%md;
        }
      } else modify(x,y+1,bx,x-1);
    } else {
      if (bx<by) {
        r=zcount(x,(bx+1)*BS,bx);
        r=(r+zcount(by*BS,y+1,by))%md;
        for (i=bx+1; i<by; i++) r=(r+b[i])%md;
      } else r=zcount(x,y+1,bx);
      printf("%d\n",r);
    }
  }
  return 0;
}
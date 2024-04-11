#include <stdio.h>
#include <memory.h>
const long long SZ=303;
int n,m,t,x,y,z,bx,by,tm,i,p,a[100500],al[100500],b[100500],bl[100500];
long long r,c[100500],s[100500],ns[100500];
bool u[100500];
long long aa(long long x) { return (x<0)?-x:x; }
void modify(int x, int y, int z, int bx, bool nu=true) {
  if (!u[bx]) {
    for (int i=bx*SZ; i<(bx+1)*SZ; i++) c[i]+=ns[bx];
    ns[bx]=0;
  }
  for (int i=x; i<=y; i++) {
    if (al[i]>=bl[bx]) p=a[i]; else p=b[bx];
    c[i]+=aa(z-p);
    s[bx]+=aa(z-p);
    a[i]=z;
    al[i]=tm;
  }
  u[bx]=nu;
}
long long count(int x, int y, int bx) {
  long long r=0;
  for (int i=x; i<=y; i++) r+=c[i]+ns[bx];
  return r;
}
int main() {
  scanf("%d%d",&n,&m);
  for (i=0; i<n; i++) a[i]=i+1;
  memset(u,true,sizeof(u));
  for (tm=1; tm<=m; tm++) {
    scanf("%d%d%d",&t,&x,&y);
    bx=(--x)/SZ;
    by=(--y)/SZ;
    if (t==1) {
      scanf("%d",&z);
      if (bx<by) {
        modify(x,(bx+1)*SZ-1,z,bx);
        modify(by*SZ,y,z,by);
        for (i=bx+1; i<by; i++) {
          if (!u[i]) {
            s[i]+=aa(z-b[i])*SZ;
            ns[i]+=aa(z-b[i]);
          } else modify(i*SZ,(i+1)*SZ-1,z,i,false);
          b[i]=z;
          bl[i]=tm;
        }
      } else modify(x,y,z,bx);
    } else {
      if (bx<by) {
        r=count(x,(bx+1)*SZ-1,bx);
        r+=count(by*SZ,y,by);
        for (i=bx+1; i<by; i++) r+=s[i];
      } else r=count(x,y,bx);
      printf("%I64d\n",r);
    }
    //for (i=0; i<=n; i++) printf("(%d %d %d), ",a[i],al[i],c[i]); puts("");
    //for (i=0; i<=(n/SZ)+1; i++) printf("[%d %d %d %d %d], ",b[i],bl[i],int(s[i]),int(ns[i]),u[i]); puts("");
  }
  return 0;
}
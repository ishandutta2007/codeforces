#include <bits/stdc++.h>
using namespace std;
const int MX=(1<<15)+2,md=1000000007;
int n,m,i,j,k,msk,a[15],b[MX],pos[15];
long long rp,rq,zp,zq,curp,curq,cp[MX],cq[MX],p[15][15],q[15][15];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void mul(long long& xp, long long& xq, long long yp, long long yq) {
  xp=(xp*yp)%md;
  xq=(xq*yq)%md;
}
void sub(long long& xp, long long& xq, long long yp, long long yq) {
  xp=(xp*yq+md-((xq*yp)%md))%md;
  xq=(xq*yq)%md;
}
void inc(long long& xp, long long& xq, long long yp, long long yq) {
  xp=(xp*yq+xq*yp)%md;
  xq=(xq*yq)%md;
}
int main() {
  scanf("%d",&n);
  for (i=0; i<n; i++) {
    scanf("%d",&a[i]);
    for (j=0; j<i; j++) {
      p[i][j]=a[i];
      p[j][i]=a[j];
      q[i][j]=q[j][i]=a[i]+a[j];
    }
  }
  rp=0;
  rq=1;
  for (i=1; i<(1<<n); i++) {
    b[i]=b[i/2]+(i&1);
    cp[i]=zp=1;
    cq[i]=zq=1;
    for (m=j=0; j<n; j++) if ((i>>j)&1) {
      pos[m++]=j;
      for (k=0; k<n; k++) if (((i>>k)&1)==0) mul(zp,zq,p[j][k],q[j][k]);
    }
    for (msk=(i&(i-1)); msk>0; msk=((msk-1)&i)) {
      curp=cp[msk];
      curq=cq[msk];
      for (j=0; j<m; j++) if ((msk>>pos[j])&1)
        for (k=0; k<m; k++) if (((msk>>pos[k])&1)==0)
          mul(curp,curq,p[pos[j]][pos[k]],q[pos[j]][pos[k]]);
      sub(cp[i],cq[i],curp,curq);
    }
    //printf("%d(%d) ==%lld/%lld\n",i,b[i],cp[i],cq[i]);
    inc(rp,rq,(((b[i]*cp[i])%md)*zp)%md,(cq[i]*zq)%md);
    //printf("Z = %lld/%lld\n",zp,zq);
    //printf("R = %lld/%lld\n",rp,rq);
  }
  printf("%lld\n",(rp*pw(rq,md-2))%md);
  return 0;
}
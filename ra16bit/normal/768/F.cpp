#include <cstdio>
#include <algorithm>
using namespace std;
const int MX=200200,md=1000000007;
int z,w,nw,mx,h,i;
long long AP,AQ,BP,BQ,ap,aq,bp,bq,cp,cq,dp,dq,f[MX];//,o[MX];
long long pw(int a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void dcp() {
  cp=(cp*dq+dp*cq)%md;
  cq=(cq*dq)%md;
}
int main() {
  for (/*o[0]=*/f[0]=i=1; i<MX; i++) {
    f[i]=(f[i-1]*i)%md;
    //o[i]=pw(f[i],md-2);
  }
  scanf("%d%d%d",&z,&w,&h);
  if (w==0) {
    puts("1");
    return 0;
  }
  mx=min(z+1,w);
  for (AQ=BQ=i=1; i<=mx; i++) {
    cp=int(z==0); cq=1;
    if (i>1) {
      dp=f[z-1];
      dq=(f[z-(i-1)]*f[i-2])%md;
      dcp();
    }
    if (z>=i) {
      dp=(2*f[z-1])%md;
      dq=(f[z-i]*f[i-1])%md;
      dcp();
    }
    if (z>=i+1) {
      dp=f[z-1];
      dq=(f[z-(i+1)]*f[i])%md;
      dcp();
    }
    if ((h+1LL)*i<=w) {
      nw=w-(h+1)*i;
      //H(nw,i)=C(nw+i-1,nw)
      ap=(cp*f[nw+i-1])%md;
      aq=(cq*((f[nw]*f[i-1])%md))%md;
    } else {
      ap=0;
      aq=1;
    }
    AP=(AP*aq+ap*AQ)%md;
    AQ=(AQ*aq)%md;
    //H(w-i,i)=C(w-i+(i-1),w-i)
    bp=(cp*f[w-1])%md;
    bq=(cq*((f[w-i]*f[i-1])%md))%md;
    BP=(BP*bq+bp*BQ)%md;
    BQ=(BQ*bq)%md;
  }
  AP=(AP*BQ)%md;
  AQ=(AQ*BP)%md;
  printf("%d\n",int((AP*pw(AQ,md-2))%md));
  return 0;
}
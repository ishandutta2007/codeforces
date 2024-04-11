#include <bits/stdc++.h>
using namespace std;
const int MX=200200,BS=522,md=998244353;
int t,n,m,num,cnt,x,y,i,j,le,ri,mid,prv,stptr,ptr,bptr,nptr,nxt[BS],add[BS],st[BS],fin[BS],a[MX],b[MX];
long long f[2*MX],o[2*MX];
long long pw(long long a, int b) {
  if (b==0) return 1LL;
  if (b&1) return (pw(a,b-1)*a)%md;
  long long x=pw(a,b/2);
  return (x*x)%md;
}
void createbptr() {
  bptr=num++;
  add[bptr]=0;
  st[bptr]=fin[bptr]=cnt;
  a[cnt++]=y;
}
int main() {
  for (f[0]=o[0]=i=1; i<2*MX; ++i) {
    f[i]=(f[i-1]*i)%md;
    o[i]=pw(f[i],md-2);
  }
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&n,&m);
    if (m==0) {
      printf("%d\n",int((((f[n+n-1]*o[n])%md)*o[n-1])%md));
      continue;
    }
    scanf("%d%d",&x,&y);
    stptr=0;
    a[0]=++y;
    add[0]=st[0]=fin[0]=0;
    nxt[0]=-1;
    num=1;
    cnt=1;
    for (i=1; i<m; i++) {
      scanf("%d%d",&x,&y);
      prv=-1;
      for (ptr=stptr; ptr!=-1; ptr=nxt[ptr]) {
        x=y-add[ptr];
        if (x<=a[fin[ptr]]) {
          if (x<=a[st[ptr]]) {
            if (x<a[st[ptr]]) {
              createbptr();
              if (prv==-1) stptr=bptr; else nxt[prv]=bptr;
              nxt[bptr]=ptr;
              ptr=bptr;
            }
          } else {
            le=st[ptr];
            ri=fin[ptr];
            while (le<ri) {
              mid=(le+ri)/2;
              if (x<=a[mid]) ri=mid; else le=mid+1;
            }
            nptr=num++;
            st[nptr]=ri;
            fin[nptr]=fin[ptr];
            add[nptr]=add[ptr];
            nxt[nptr]=nxt[ptr];
            fin[ptr]=ri-1;
            if (x<a[ri]) {
              createbptr();
              nxt[ptr]=bptr;
              nxt[bptr]=nptr;
            } else nxt[ptr]=nptr;
            ptr=nxt[ptr];
          }
          break;
        }
        prv=ptr;
      }
      if (ptr==-1) {
        createbptr();
        if (prv==-1) stptr=bptr; else nxt[prv]=bptr;
        nxt[bptr]=-1;
        ptr=bptr;
      }
      for (; ptr!=-1; ptr=nxt[ptr]) ++add[ptr];
      if (num>=BS-2) {
        cnt=0;
        for (ptr=stptr; ptr!=-1; ptr=nxt[ptr]) for (j=st[ptr]; j<=fin[ptr]; ++j) b[cnt++]=a[j]+add[ptr];
        for (j=0; j<cnt; j++) a[j]=b[j];
        stptr=0;
        add[0]=st[0]=0;
        fin[0]=cnt-1;
        nxt[0]=-1;
        num=1;
      }
    }
    cnt=n-1-cnt;
    printf("%d\n",int((((f[n+cnt]*o[cnt])%md)*o[n])%md));
  }
  return 0;
}
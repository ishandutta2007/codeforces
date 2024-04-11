#include <bits/stdc++.h>
using namespace std;
const int MX=1100100;
int t,h,g,it,n,m,i,w,le,ri,prv,nxt,a[MX],c[MX],r[MX];
long long tot;
bool fin[MX];
int main() {
  scanf("%d",&t);
  while (t--) {
    scanf("%d%d",&h,&g);
    n=(1<<h); m=(1<<g); tot=0;
    for (i=1; i<n; i++) {
      scanf("%d",&a[i]);
      tot+=a[i];
    }
    for (i=n-1; i>0; i--) {
      c[i]=int(i>=m);
      fin[i]=int(i*2>=n);
      if (i*2<n) c[i]+=c[i*2];
      if (i*2+1<n) c[i]+=c[i*2+1];
    }
    //for (i=1; i<n; i++) printf("%d(%d),",a[i],c[i]); puts("~~~");
    for (it=0; it<n-m; it++) {
      i=w=1;
      while (!fin[i]) {
        c[i]--;
        le=i*2;
        ri=i*2+1;
        if (a[le]==0) {
          i=ri;
        } else if (a[ri]==0) {
          i=le;
        } else
        if (a[le]>a[ri]) {
          if (c[le]==0) i=w=ri; else i=le;
        } else if (c[ri]==0) i=w=le; else i=ri;
      }
      if (i>1 && c[i^1]==0) fin[i/2]=true;
      //printf("got w=%d (%d)\n",w,a[w]);
      r[it]=w;
      tot-=a[w];
      prv=0;
      for (prv=0; i>=w; i/=2) {
        nxt=a[i];
        //printf("mv %d, ",nxt);
        a[i]=prv;
        prv=nxt;
      }
      //puts("");
      //for (i=1; i<n; i++) printf("%d(%d),",a[i],c[i]); puts("~~");
    }
    printf("%I64d\n",tot);
    for (i=0; i<it; i++) printf("%d ",r[i]); puts("");
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,d,b,i,l,lx,ly,r,rx,ry,res;
long long a[100100],sl,sr,cur,c,v;
void inc(int x, long long v) {
  a[x]+=v;
  if (x>=l && x<=lx) {
    sl+=v;
    if (x<ly) ly=x;
  }
  if (x>=rx && x<=r) {
    sr+=v;
    if (x>ry) ry=x;
  }
}
void dec(int x, long long v) {
  a[x]-=v;
  if ((x>=l || x>=ly) && x<=lx) sl-=v;
  if (x>=rx && (x<=r || x<=ry)) sr-=v;
}
int main() {
  scanf("%d%d%d",&n,&d,&b);
  for (i=1; i<=n; i++) scanf("%lld",&a[i]);
  for (l=lx=ly=1, r=rx=ry=n; l<r; l++, r--) {
    for (i=0; lx<=n && i<=d; i++, lx++) sl+=a[lx];
    for (i=0; rx>0 && i<=d; i++, rx--) sr+=a[rx];
//    for (i=1; i<=n; i++) printf("%d ",int(a[i]));
//    printf("[%d..%d..%d] %lld [%d..%d..%d] %lld\n",l,ly,lx,sl,rx,ry,r,sr);
    if (sl>=b && sr>=b) {
      for (cur=b; cur>0 && ly<=lx; ) {
        c=min(cur,a[ly]);
        cur-=c;
        dec(ly,c);
        if (a[ly]==0) ly++;
      }
      for (cur=b; cur>0 && ry>=rx; ) {
        c=min(cur,a[ry]);
        cur-=c;
        dec(ry,c);
        if (a[ry]==0) ry--;
      }
    } else res++;
  }
  printf("%d\n",res);
  return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;
int m,md,res;
long long n,l,r,u,v,le,ri,r1,r2;
void rec(long long L, long long R, long long l, long long r, long long e, int x) {
  if (L==l && R==r) {
    if (x==0) {
      r1=v+1; r2=v+2;
      if (r1&1) r2/=2; else r1/=2;
      r1%=md; r2%=md;
      res=(res+r1*r2)%md;
      r1=u; r2=u+1;
      if (r1&1) r2/=2; else r1/=2;
      r1%=md; r2%=md;
      res=(res+md-(r1*r2)%md)%md;
    } else {
      le=((u>>x)<<x)+e;
      ri=((v>>x)<<x)+e;
      if (le<u) le+=1LL<<x;
      if (ri>v) ri-=1LL<<x;
      if (le<=ri) {
        r1=le+ri+2;
        r2=(ri>>x)-(le>>x)+1;
        if (r1&1) r2/=2; else r1/=2;
        r1%=md; r2%=md;
        res=(res+r1*r2)%md;
      }
    }
    return;
  }
  long long m=(L+R)/2;
  if (l<=m) rec(L,m,l,min(r,m),e,x+1);
  if (m<r) rec(m+1,R,max(m+1,l),r,e+(1LL<<x),x+1);
}
int main() {
  scanf("%I64d%d%d",&n,&m,&md);
  while (m--) {
    scanf("%I64d%I64d%I64d%I64d",&l,&r,&u,&v);
    if (u>n) { puts("0"); continue; }
    if (v>n) v=n;
    res=0; u--; v--;
    rec(0,n-1,l-1,r-1,0,0);
    printf("%d\n",res);
  }
  return 0;
}
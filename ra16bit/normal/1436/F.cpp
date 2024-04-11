#include <bits/stdc++.h>
using namespace std;
const int MX=100100,md=998244353;
int m,i,j,a[MX],b[MX],cnt[MX],v[MX],w[MX];
long long n,cur,cc,sum,r,s,p,z,res,zz;
bool ok[MX];
long long ins(long long x) {
  return ((x*(x-1LL))/2)%md;
}
long long pw2(long long b) {
  if (b==0) return 1LL;
  if (b&1) return (pw2(b-1)*2LL)%md;
  long long x=pw2(b/2);
  return (x*x)%md;
}
int main() {
  ok[1]=true;
  for (z=2; z<MX; z++) if (!v[z]) {
    for (j=z; j<MX; j+=z) { ++v[j]; w[j]=z; }
    ok[z]=true;
  } else ok[z]=((z/w[z])%w[z]>0 && ok[z/w[z]]);
  scanf("%d",&m);
  for (i=1; i<=m; i++) {
    scanf("%d%d",&a[i],&cnt[i]);
    b[a[i]]=i;
  }
  for (zz=1; zz<MX; zz++) if (ok[zz]) {
    sum=s=r=n=0;
    for (j=zz; j<MX; j+=zz) if (b[j]) {
      i=b[j];
      n+=cnt[i];
      cur=a[i];
      cc=(cnt[i]*cur)%md;
      r=(r+cc*sum)%md;
      sum=(sum+cc)%md;
      cur=(cur*cur)%md;
      r=(r+cur*ins(cnt[i]))%md;
      s=(s+cur*cnt[i])%md;
      //printf("r=%I64d s=%I64d\n",r,s);
    }
    if (n<=1) continue;
    p=pw2(n-2LL);
    z=((n%md)*p)%md;
    //printf("z=%I64d r=%I64d s=%I64d p=%I64d\n",z,r,s,p);
    r=((z*r)%md+s*((p*((n-1LL)%md))%md))%md;
    //printf("r=%d (%d: %d)\n",int(r),zz,v[zz]);
    if (v[zz]&1) res=(res+md-r)%md; else res=(res+r)%md;
  }
  printf("%d\n",int(res));
  return 0;
}
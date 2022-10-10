#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,d,a,b,t,i,k,le,ri,cle,cri;
long long inf,len,pr,f[150015],l[150015],r[150015];
int main() {
  inf=-10000000000000000LL;
  scanf("%d%d%d",&n,&m,&d);
  for (k=0; k<m; k++) {
    scanf("%d%d%d",&a,&b,&t);
    len=(t-pr)*2LL*d+1;
    if (len>n) len=n;
    for (i=1; i<=n; i++) if ((i-1)%len==0) l[i]=f[i]; else l[i]=max(l[i-1],f[i]);
    for (i=n; i>=1; i--) if (i%len==0 || i==n) r[i]=f[i]; else r[i]=max(r[i+1],f[i]);
    for (i=1; i<=n; i++) {
      le=max(1LL,i-(t-pr)*d);
      ri=min((long long)n,i+(t-pr)*d);
      if (le%len>0 && le<n) cle=min((long long)n,le-le%len+len); else cle=le;
      if ((ri-1)%len) {
        cri=ri-ri%len;
        if (ri%len==0) cri-=len;
        cri++;
      } else cri=ri;
      f[i]=inf;
      if (cle<=ri) f[i]=max(f[i],r[le]);
      //printf("%I64d (%d..%d) ",f[i],le,ri);
      if (cri>=le) f[i]=max(f[i],l[ri]);
      //printf("%I64d (%d..%d %d %d) ",f[i],le,ri,cle,cri);
      f[i]+=b-abs(a-i);
      //printf("%I64d (%d..%d) \n",f[i],le,ri);
    }
    //puts("");
    pr=t;
  }
  for (i=1; i<=n; i++) inf=max(inf,f[i]);
  printf("%I64d\n",inf);
  return 0;
}
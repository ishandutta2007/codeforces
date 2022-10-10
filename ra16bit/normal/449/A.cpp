#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,k,l,r,h,cn,cm;
long long an,am,res;
long long get(int cn, int cm) {
  an=n/cn;
  am=m/cm;
  return an*am;
}
int main() {
  scanf("%d%d%d",&n,&m,&k);
  if (n+m-2<k) {
    puts("-1");
    return 0;
  }
  l=1; r=min(n,m);
  while (l<r) {
    h=(l+r)/2+1;
    cn=n/h-1;
    cm=m/h-1;
    if (cn+cm>=k) l=h; else r=h-1;
  }
  cn=min(n/r-1,k);
  res=get(cn+1,k-cn+1);
  cm=min(m/r-1,k);
  res=max(res,get(k-cm+1,cm+1));
  if (n>1) {
    cn=min(n-1,k);
    res=max(res,get(cn+1,k-cn+1));
  }
  if (m>1) {
    cm=min(m-1,k);
    res=max(res,get(k-cm+1,cm+1));
  }
  printf("%I64d\n",res);
  return 0;
}